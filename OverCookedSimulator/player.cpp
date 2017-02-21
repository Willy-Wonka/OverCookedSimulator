//
//  player.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-18.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "player.hpp"

Player::Player(int mode)
{
	switch (mode)
	{
		case SP_MODE:
			singlePlayer();
			break;
		case MP_MODE:
			multiPlayer();
			break;
		default:
			singlePlayer();
			break;
	}
	cout << "A player joined\n";
}

Player::~Player()
{
	cout << "A player left\n";
}

void Player::cutTomato(City1* c1)
{
	cout << "start cut tomato\n";
	usleep(CUT_TOMATO * MICROSECONDS);
	cout << "tomato cutted\n";
	c1->setCuttedTomato(c1->getCuttedTomato() + 1);
}
