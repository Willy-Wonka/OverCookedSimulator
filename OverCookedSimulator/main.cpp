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

int main(int argc, const char * argv[])
{
	int const CITY1_TIMER = 5;	// 300
	City1 c1(CITY1_TIMER);
	Player p1(MP_MODE);
	Player p2(MP_MODE);
	thread tP1, tP2;
	
	c1.startGame();
	
	while (c1.isGameOver())	{ }	// wait for game to start
	
	vector<Order> city1Orders;
	do	// run until game over
	{
		//		p1Action(&tP1);
		city1Orders = c1.getCity1Orders();
		if (city1Orders.size() <= 0) continue;
		
		bool processing = false;
		for (int i = 0; i < city1Orders.size(); i++)
		{
			int processOrder = city1Orders[i].getOrder();
			
			switch (processOrder)
			{
				case ORDER_HAMBURGER1:
					if (c1.getCuttedBeef() < 1)
						tP1 = thread(&Player::cutBeef, &p1, &c1);
					processing = true;
					break;
				case ORDER_HAMBURGER2:
					if (c1.getCuttedBeef() < 1)
						tP1 = thread(&Player::cutBeef, &p1, &c1);
					else if (c1.getCuttedCabbage() < 1)
						tP1 = thread(&Player::cutCabbage, &p1, &c1);
					processing = true;
					break;
				case ORDER_HAMBURGER3:
					if (c1.getCuttedBeef() < 1)
						tP1 = thread(&Player::cutBeef, &p1, &c1);
					else if (c1.getCuttedCabbage() < 1)
						tP1 = thread(&Player::cutCabbage, &p1, &c1);
					else if (c1.getCuttedTomato() < 1)
						tP1 = thread(&Player::cutTomato, &p1, &c1);
					processing = true;
					break;
				default:
					break;
			}
			if (processing && tP1.joinable())
			{
				tP1.join();
				break;
			}
		}
		
		c1.printOrders();
		c1.printIngredients();
		
	} while (!c1.isGameOver());
	
	
//	if (city1Orders.size() > 0)
		cout << "xxx " << city1Orders.size() << endl;
	
	return 0;
}


//	future<void> fC1StartGame = async(launch::async, &City1::startGame, &c1);
//	thread tGameStart(&City1::startGame, &c1);

//	future_status fsC1StartGame;

//		fsC1StartGame = fC1StartGame.wait_for(chrono::seconds(0));
//		if (fsC1StartGame == future_status::ready)	// if countdown finished
//			break;
	
//	if (tGameStart.joinable())
//		tGameStart.join();













