//
//  player.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-18.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "player.hpp"

player::player(int mode)
{
	switch (mode)
	{
		case sp:
			singlePlayer();
			break;
		case mp:
			multiPlayer();
			break;
		default:
			singlePlayer();
			break;
	}
	cout << "A player joined\n";
}

player::~player()
{
	cout << "A player left\n";
}

void player::cutTomato(city1* c1)
{
	cout << "start cut tomato\n";
	usleep(CUT_TOMATO * MICROSECONDS);
	cout << "tomato cutted\n";
	c1->setCuttedTomato(c1->getCuttedTomato() + 1);
}
