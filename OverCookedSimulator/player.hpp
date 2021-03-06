//
//  player.hpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-18.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "city1.hpp"

enum
{
	SP_MODE,	// single player
	MP_MODE		// multi player
};

class Player
{
public:
	static int getNumOfPlayers() { return numOfPlayers;	}
	
	Player(int = SP_MODE);
	~Player();
	
	void cutBeef(City1*);
	void cutTomato(City1*);
	void cutCabbage(City1*);
	void cleanPlate(City1*);
	void deliverOrder(City1*, int);
	
private:
	int const MICROSECONDS = 1000000;	// 1 second
	int const COOLDOWN_MICROSECONDS = 500000;	// 0.5 seconds
	
	static int numOfPlayers;
	
	int cutBeefTime;
	int friedBeefTime;
	int cutTomatoTime;
	int cutCabbageTime;
	int deliverTime;
	int diningTime;
	int washPlateTime;
	int hamburgerWaitTime;
	
	void singlePlayer();
	void multiPlayer();
};
#endif /* player_hpp */
