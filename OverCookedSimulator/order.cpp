//
//  order.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-22.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "order.hpp"

#include <sys/time.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <iostream>

int Order::numOfOrders = 0;

Order::Order(int food, int waitTime)
: foodKind(food), WAITE_TIME(waitTime)
{
	foodKind = ORDER_HAMBURGER;
}

Order::~Order() { }

int Order::makeOrder()
{
	srand((unsigned)time(NULL));
	switch (rand() % 3 + 1)
	{
		case 1:
			foodKind = ORDER_HAMBURGER1;
			break;
		case 2:
			foodKind = ORDER_HAMBURGER2;
			break;
		case 3:
			foodKind = ORDER_HAMBURGER3;
			break;
		default:
			break;
	}
	
	// Wall Time
	struct timeval time;
	gettimeofday(&time, NULL);
	startTime = (double)time.tv_sec + (double)time.tv_usec * .000001;
	
	return getOrder();
}

int Order::getOrder()
{
	return foodKind;
}

bool Order::orderExpired()
{
	// Elapsed Wall Time
	struct timeval time;
	gettimeofday(&time, NULL);
	
	return ((double)time.tv_sec + (double)time.tv_usec * .000001 - startTime) > WAITE_TIME ? true : false;
}
















