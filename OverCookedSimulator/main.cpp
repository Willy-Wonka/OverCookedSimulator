//
//  main.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-17.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include <stdio.h>

#include <thread>
#include <future>
#include <iostream>
using namespace std;

#include "city1.hpp"
#include "player.hpp"

//void p1Action(thread* tP1)
//{
//	(*tP1) = thread(&Player::cutTomato, &p1, &c1);
//	tP1->join();
//}

// player actions
enum
{
	ACTION_DO_NOTHING,
	ACTION_CUT_BEEF,
	ACTION_CUT_CABBAGE,
	ACTION_CUT_TOMATO,
	ACTION_CLEAN_PLATE,
	ACTION_DELIVER,
};

int p1Action(vector<Order>, City1&);
bool orderCompleted(int, City1&);

int main(int argc, const char * argv[])
{
	int const CITY1_TIMER = 50;	// 300
	City1 c1(CITY1_TIMER);
	Player p1(MP_MODE);
	Player p2(MP_MODE);
	thread tP1, tP2;
	
	c1.startGame();
	
	while (c1.isGameOver())	{ }	// wait for game to start
	
//	vector<Order> city1Orders;
	do	// run until game over
	{
		switch (p1Action(c1.getCity1Orders(), c1))
		{
			case ACTION_CUT_BEEF:
				tP1 = thread(&Player::cutBeef, &p1, &c1);
				break;
			case ACTION_CUT_CABBAGE:
				tP1 = thread(&Player::cutCabbage, &p1, &c1);
				break;
			case ACTION_CUT_TOMATO:
				tP1 = thread(&Player::cutTomato, &p1, &c1);
				break;
			case ACTION_CLEAN_PLATE:
				tP1 = thread(&Player::cleanPlate, &p1, &c1);
				break;
			case ACTION_DELIVER:
				tP1 = thread(&Player::deliverOrder, &p1, &c1, 0);
				break;
			default:
				break;
		}
		
		if (tP1.joinable())
			tP1.join();
		
//		c1.printOrders();
		c1.printIngredients();
		
	} while (!c1.isGameOver());
	
	
//	if (city1Orders.size() > 0)
//		cout << "xxx " << city1Orders.size() << endl;
	
	return 0;
}

int p1Action(vector<Order> city1Orders, City1& c1)
{
	int action = ACTION_DO_NOTHING;
	if (city1Orders.size() <= 0) return ACTION_DO_NOTHING;
	
	bool hasAction = false;
	int cuttedBeefNeeded = 1;
	int cuttedCabbageNeeded = 1;
	int cuttedTomatoNeeded = 1;
	int cleanPlateNeeded = 1;
	
	if (orderCompleted(city1Orders[0].getOrder(), c1))
		return ACTION_DELIVER;
	
	for (int i = 0; i < city1Orders.size(); i++)
	{
		int processOrder = city1Orders[i].getOrder();
		
		// Ingredients process
		switch (processOrder)
		{
			case ORDER_HAMBURGER1:
				if (c1.getCuttedBeef() < cuttedBeefNeeded)
				{
					action = ACTION_CUT_BEEF;
					hasAction = true;
					break;
				}
				else
					cuttedBeefNeeded++;
				
				if (c1.getCleanPlate() < cleanPlateNeeded)
				{
					if (c1.getDirtyPlate() > 0)
					{
						action = ACTION_CLEAN_PLATE;
						hasAction = true;
						break;
					}
				}
				else
					cleanPlateNeeded++;
				
				break;
				
			case ORDER_HAMBURGER2:
				if (c1.getCuttedBeef() < cuttedBeefNeeded)
				{
					action = ACTION_CUT_BEEF;
					hasAction = true;
					break;
				}
				else
					cuttedBeefNeeded++;
				
				if (c1.getCuttedCabbage() < cuttedCabbageNeeded)
				{
					action = ACTION_CUT_CABBAGE;
					hasAction = true;
					break;
				}
				else
					cuttedCabbageNeeded++;
				
				if (c1.getCleanPlate() < cleanPlateNeeded)
				{
					if (c1.getDirtyPlate() > 0)
					{
						action = ACTION_CLEAN_PLATE;
						hasAction = true;
						break;
					}
				}
				else
					cleanPlateNeeded++;
				
				break;
				
			case ORDER_HAMBURGER3:
				if (c1.getCuttedBeef() < cuttedBeefNeeded)
				{
					action = ACTION_CUT_BEEF;
					hasAction = true;
					break;
				}
				else
					cuttedBeefNeeded++;
				
				if (c1.getCuttedCabbage() < cuttedCabbageNeeded)
				{
					action = ACTION_CUT_CABBAGE;
					hasAction = true;
					break;
				}
				else
					cuttedCabbageNeeded++;
				
				if (c1.getCuttedTomato() < cuttedTomatoNeeded)
				{
					action = ACTION_CUT_TOMATO;
					hasAction = true;
					break;
				}
				else
					cuttedTomatoNeeded++;
				
				if (c1.getCleanPlate() < cleanPlateNeeded)
				{
					if (c1.getDirtyPlate() > 0)
					{
						action = ACTION_CLEAN_PLATE;
						hasAction = true;
						break;
					}
				}
				else
					cleanPlateNeeded++;
				
				break;
				
			default:
				break;
		}
		
		if (hasAction) break;
	}
	
	return action;
}

bool orderCompleted(int order, City1& c1)
{
	bool completed = true;
	
	switch (order)
	{
		case ORDER_HAMBURGER3:
			if (!c1.hasCuttedTomato())
				completed = false;
		case ORDER_HAMBURGER2:
			if (!c1.hasCuttedCabbage())
				completed = false;
		case ORDER_HAMBURGER1:
			if (!c1.hasCuttedBeef())
				completed = false;
		default:
			if (!c1.hasCleanPlate())
				completed = false;
			break;
	}
	
	return completed;
}

//	future<void> fC1StartGame = async(launch::async, &City1::startGame, &c1);
//	thread tGameStart(&City1::startGame, &c1);

//	future_status fsC1StartGame;

//		fsC1StartGame = fC1StartGame.wait_for(chrono::seconds(0));
//		if (fsC1StartGame == future_status::ready)	// if countdown finished
//			break;
	
//	if (tGameStart.joinable())
//		tGameStart.join();













