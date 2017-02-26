//
//  city1.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-17.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "city1.hpp"

#include <sys/time.h>
#include <unistd.h>

#include <cmath>
#include <iostream>
using namespace std;


City1::City1(int seconds)
: CITY1_TIME_LIMIT(seconds)	// default 300s
{
	gameStarted = false;
	setCuttedTomato(0);
	setCuttedCabbage(0);
	setCuttedBeef(0);
	setFriedBeef(0);
	setCleanPlate(2);
	setDirtyPlate(0);
	
	city1Orders.reserve(ORDER_SIZE);
	
	ordersDelivered = 0;
	tips = 0;
	ordersFailed = 0;
	total = 0;
}

City1::~City1()
{
	if (tCountdown.joinable())
		tCountdown.join();
	if (tMakeOrders.joinable())
		tMakeOrders.join();
}

void City1::startGame()
{
	tMakeOrders = thread(&City1::makeOrders, this);
	tCountdown = thread(&City1::countdown, this, CITY1_TIME_LIMIT);
}

bool City1::isGameOver()
{
	return !gameStarted;
}

vector<Order> City1::getCity1Orders()
{
	return city1Orders;
}

void City1::orderDelivered(int orderNum)
{
	switch (city1Orders[orderNum].getOrder())
	{
		case ORDER_HAMBURGER3:
			setCuttedTomato(getCuttedTomato() - 1);
		case ORDER_HAMBURGER2:
			setCuttedCabbage(getCuttedCabbage() - 1);
		case ORDER_HAMBURGER1:
			setCuttedBeef(getCuttedBeef() - 1);
		default:
			break;
	}
	city1Orders.erase(city1Orders.begin() + orderNum);
	ordersDelivered++;
}

void City1::printTotalRevenue()
{
	int totalRevenue = ordersDelivered * 20;
	string result = "$" + to_string(totalRevenue) + "\t";
	cout << result;
}

void City1::printOrders()
{
	string orders = "";
	for (int i = 0; i < city1Orders.size(); i++)
		orders += to_string(city1Orders[i].getOrder()) + "\t";
	orders += "\n";
	cout << orders;
}

void City1::printIngredients()
{
	string ingredients = "";
	
	if (hasCuttedBeef())
		ingredients += "Ctd Beef: " + to_string(getCuttedBeef()) + "\t";
	if (hasFriedBeef())
		ingredients += "Frd Beef: " + to_string(getFriedBeef()) + "\t";
	if (hasCuttedCabbage())
		ingredients += "Ctd Cabbage: " + to_string(getCuttedCabbage()) + "\t";
	if (hasCuttedTomato())
		ingredients += "Ctd Tomato: " + to_string(getCuttedTomato()) + "\t";
	if (hasCleanPlate())
		ingredients += "Cln Plate: " + to_string(getCleanPlate()) + "\t";
	if (hasDirtyPlate())
		ingredients += "Dty Plate: " + to_string(getDirtyPlate()) + "\t";
	ingredients += "\n";
	cout << ingredients;
}

bool City1::useCuttedTomato()
{
	if (!hasCuttedTomato())
		return false;
	else
		cuttedTomato--;
	return true;
}

bool City1::useCuttedCabbage()
{
	if (!hasCuttedCabbage())
		return false;
	else
		cuttedCabbage--;
	return true;
}

bool City1::useCuttedBeef()
{
	if (!hasCuttedBeef())
		return false;
	else
		cuttedBeef--;
	return true;
}

bool City1::useFriedBeef()
{
	if (!hasFriedBeef())
		return false;
	else
		friedBeef--;
	return true;
}

bool City1::useCleanPlate()
{
	if (!hasCleanPlate())
		return false;
	else
		cleanPlate--;
	return true;
}

bool City1::useDirtyPlate()
{
	if (!hasDirtyPlate())
		return false;
	else
		dirtyPlate--;
	return true;
}

void City1::makeOrders()
{
	while (isGameOver()) { }	// wait for game to start
	
	do // run until game over
	{
		if (city1Orders.size() < ORDER_SIZE)
		{
			Order order;
			order.makeOrder();
			city1Orders.push_back(order);
		}
		
		usleep(1 * 1000000);
	} while (!isGameOver());
	cout << "Game Over.\n";
}

void City1::countdown(int seconds)
{
	double duration = 0;
	int timer = 0;
	cout << "Start!\n";
	
	// Elapsed Wall Time
	struct timeval time;
	gettimeofday(&time, NULL);
	double startTime = (double)time.tv_sec + (double)time.tv_usec * .000001;
	
	gameStarted = true;
	while (duration < seconds)
	{
		gettimeofday(&time, NULL);
		duration = (double)time.tv_sec + (double)time.tv_usec * .000001 - startTime;
		
		double fractional, integer;
		fractional = modf(duration, &integer);	// get the integer part
		// if pass one whole second
		if (timer == integer)
		{
			int secondsLeft = seconds - timer;
			int minutesLeft = secondsLeft / 60;
			secondsLeft -= minutesLeft * 60;
			
			// print out time left in 00:00 form
			string timeLeft = "\n";
			if (minutesLeft < 10)
				timeLeft += "0";
			timeLeft += to_string(minutesLeft) + ":";
			if (secondsLeft < 10)
				timeLeft += "0";
			timeLeft += to_string(secondsLeft) + "\t";
			
			cout << timeLeft;
			this->printTotalRevenue();
			this->printOrders();
			
			timer++;
		}
	}
	gameStarted = false;
	cout << "Time Out!\n";
}








