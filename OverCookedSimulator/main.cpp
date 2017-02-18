//
//  main.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-17.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <thread>
using namespace std;

#include "city1.hpp"

void countdown(int seconds)
{
	clock_t start = clock();
	double duration = 0;
	int timer = 0;
	
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
}

int main(int argc, const char * argv[])
{
	int const CITY1_TIMER = 300;
//	int const CUT_TOMATO = 8;
//	int const CUT_CABBAGE = 8;
//	int const CUT_BEEF = 8;
//	int const FRIED_BEEF = 21;
//	int const DELIVER_TIME = 1;
//	int const DINING_TIME = 10;
//	int const WASH_PLATE = 3;
	int const HAMBURGER_TIME_LIMIT = 2 * 60 + 30;	// 37.5 * 4
	
	city1 c1;
	
	cout << "clean plate = " << c1.getCleanPlate() << endl;
	
	thread tCountdown(countdown, CITY1_TIMER);
	
	// insert code here...
	cout << "Hello, \n";
	
	for (int i = 0; i < 500; i++) {
		cout << i << endl;
	}
	
	tCountdown.join();
	cout << "World!\n";
	
    return 0;
}
