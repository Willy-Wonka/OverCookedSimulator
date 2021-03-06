//
//  player.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-18.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "player.hpp"

#include <unistd.h>

#include <iostream>
using namespace std;

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

void Player::cutBeef(City1* pC1)
{
	cout << "Cutting Beef\n";
	usleep(cutBeefTime * MICROSECONDS);	// cutting a tomato
	
	if (!pC1->isGameOver())
	{
		cout << "Beef cutted\n";
		pC1->setCuttedBeef(pC1->getCuttedBeef() + 1);
	}
	usleep(COOLDOWN_MICROSECONDS);	// cooldown 0.5 seconds
}

void Player::cutCabbage(City1* pC1)
{
	cout << "Cutting cabbage\n";
	usleep(cutCabbageTime * MICROSECONDS);	// cutting a tomato
	
	if (!pC1->isGameOver())
	{
		cout << "Cabbage cutted\n";
		pC1->setCuttedCabbage(pC1->getCuttedCabbage() + 1);
	}
	usleep(COOLDOWN_MICROSECONDS);	// cooldown 0.5 seconds
}

void Player::cutTomato(City1* pC1)
{
	cout << "Cutting tomato\n";
	usleep(cutTomatoTime * MICROSECONDS);	// cutting a tomato
	
	if (!pC1->isGameOver())
	{
		cout << "Tomato cutted\n";
		pC1->setCuttedTomato(pC1->getCuttedTomato() + 1);
	}
	usleep(COOLDOWN_MICROSECONDS);	// cooldown 0.5 seconds
}

void Player::cleanPlate(City1* pC1)
{
	cout << "Cleaning plate\n";
	usleep(washPlateTime * MICROSECONDS);	// washing a plate
	
	if (!pC1->isGameOver())
	{
		cout << "Plate cleaned\n";
		pC1->setCleanPlate(pC1->getCleanPlate() + 1);
		pC1->useDirtyPlate();
	}
	usleep(COOLDOWN_MICROSECONDS);	// cooldown 0.5 seconds
}


void Player::deliverOrder(City1* pC1, int orderNum)
{
	cout << "Delivering order #" << orderNum << "\n";
	usleep(deliverTime * MICROSECONDS);	// cutting a tomato
	
	if (!pC1->isGameOver())
	{
		cout << "Order delivered\n";
		pC1->orderNumDelivered(orderNum);
	}
	usleep(COOLDOWN_MICROSECONDS);	// cooldown 0.5 seconds
}

void Player::singlePlayer()
{
	cutBeefTime = 8;
	friedBeefTime = 21;
	cutCabbageTime = 8;
	cutTomatoTime = 8;
	deliverTime = 1;
	diningTime = 10;
	washPlateTime = 3;
	hamburgerWaitTime = 2 * 60 + 30;	// 37.5 * 4
}

void Player::multiPlayer()
{
	cutBeefTime = 2;
	friedBeefTime = 20;
	cutCabbageTime = 2;
	cutTomatoTime = 2;
	deliverTime = 1;
	diningTime = 10;
	washPlateTime = 3;
	hamburgerWaitTime = 2 * 60 + 30;	// 37.5 * 4
}
