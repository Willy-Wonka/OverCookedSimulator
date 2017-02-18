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
#include "player.hpp"

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
	thread tCountdown(countdown, CITY1_TIMER);
	
	city1 c1;
	player p1(mp);
	player p2(mp);
	
	cout << "clean plate = " << c1.getCleanPlate() << endl;
	
	thread cut(&player::cutTomato, p1);
	
	tCountdown.join();
	cout << "End!\n";
	
    return 0;
}
