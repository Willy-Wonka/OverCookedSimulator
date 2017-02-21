//
//  player.hpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-18.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#include "city1.hpp"

enum
{
	SP_MODE,	// single player
	MP_MODE		// multi player
};

class Player
{
public:
	Player(int = SP_MODE);
	~Player();
	
	void cutTomato(City1*);
	
	static int getNumOfPlayers() { return numOfPlayers;	}
	
private:
	int const MICROSECONDS = 1000000;
	int CUT_TOMATO;
	int CUT_CABBAGE;
	int CUT_BEEF;
	int FRIED_BEEF;
	int DELIVER_TIME;
	int DINING_TIME;
	int WASH_PLATE;
	int HAMBURGER_TIME_LIMIT;
	
	static int numOfPlayers;
	
	void singlePlayer()
	{
		CUT_TOMATO = 8;
		CUT_CABBAGE = 8;
		CUT_BEEF = 8;
		FRIED_BEEF = 21;
		DELIVER_TIME = 1;
		DINING_TIME = 10;
		WASH_PLATE = 3;
		HAMBURGER_TIME_LIMIT = 2 * 60 + 30;	// 37.5 * 4
	}
	
	void multiPlayer()
	{
		CUT_TOMATO = 2;
		CUT_CABBAGE = 2;
		CUT_BEEF = 2;
		FRIED_BEEF = 20;
		DELIVER_TIME = 1;
		DINING_TIME = 10;
		WASH_PLATE = 3;
		HAMBURGER_TIME_LIMIT = 2 * 60 + 30;	// 37.5 * 4
	}
	
	
};
#endif /* player_hpp */
