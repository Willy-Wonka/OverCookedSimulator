//
//  player.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-18.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "player.hpp"

int Player::numOfPlayers = 0;

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
	numOfPlayers++;
	cout << getNumOfPlayers() << " player(s) has joined the game!\n";
}

Player::~Player()
{
	numOfPlayers--;
	cout << "A player left the game, There are " << getNumOfPlayers() << " player(s) left!\n";
}

void Player::cutTomato(City1* pC1)
{
	cout << "start cut tomato\n";
	usleep(cutTomatoTime * MICROSECONDS);
	cout << "tomato cutted\n";
	pC1->setCuttedTomato(pC1->getCuttedTomato() + 1);
}

void Player::singlePlayer()
{
	cutTomatoTime = 8;
	cutCabbageTime = 8;
	cutBeefTime = 8;
	friedBeefTime = 21;
	deliverTime = 1;
	diningTime = 10;
	washPlateTime = 3;
	hamburgerWaitTime = 2 * 60 + 30;	// 37.5 * 4
}

void Player::multiPlayer()
{
	cutTomatoTime = 2;
	cutCabbageTime = 2;
	cutBeefTime = 2;
	friedBeefTime = 20;
	deliverTime = 1;
	diningTime = 10;
	washPlateTime = 3;
	hamburgerWaitTime = 2 * 60 + 30;	// 37.5 * 4
}
