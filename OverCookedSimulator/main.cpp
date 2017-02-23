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

int main(int argc, const char * argv[])
{
	int const CITY1_TIMER = 5;	// 300
	City1 c1(CITY1_TIMER);
	Player p1(MP_MODE);
	Player p2(MP_MODE);
	thread tP1, tP2;
	
	c1.startGame();
	
	while (c1.isGameOver())	{ }	// wait for game to start
	
	do	// run until game over
	{
		tP1 = thread(&Player::cutTomato, &p1, &c1);
		tP1.join();
		
		c1.printOrders();
		cout << "We have " << c1.getCuttedTomato() << " cutted tomatoes\n";
		
	} while (!c1.isGameOver());
	
	cout << "We have " << c1.getCuttedTomato() << " cutted tomatoes\n";
	
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













