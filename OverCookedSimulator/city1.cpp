//
//  city1.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-17.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "city1.hpp"

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
}

void City1::startGame()
{
	countdown(CITY1_TIME_LIMIT);
}

bool City1::isGameOver()
{
	return !gameStarted;
}

void City1::countdown(int seconds)
{
	clock_t start = clock();
	double duration = 0;
	int timer = 0;
	
	cout << "Start!\n";
	gameStarted = true;
	while (duration < seconds)
	{
		duration = (clock() - start) / (double) CLOCKS_PER_SEC;
		double fractional, integer;
		fractional = modf(duration, &integer);	// get the integer part
		
		// if pass one whole second
		if (timer == integer)
		{
			int secondsLeft = seconds - timer;
			int minutesLeft = secondsLeft / 60;
			secondsLeft -= minutesLeft * 60;
			
			// print out time left in 00:00 form
			string timeLeft = "";
			if (minutesLeft < 10)
				timeLeft += "0";
			timeLeft += to_string(minutesLeft) + ":";
			if (secondsLeft < 10)
				timeLeft += "0";
			timeLeft += to_string(secondsLeft) + "\n";
			
			cout << timeLeft;
			
			timer++;
		}
	}
	gameStarted = false;
	cout << "Time Out!\n";
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








