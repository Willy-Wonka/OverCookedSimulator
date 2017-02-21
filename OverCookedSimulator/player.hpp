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
	Player(int = SP_MODE);
	~Player();
	
	void cutTomato(City1*);
	
	static int getNumOfPlayers() { return numOfPlayers;	}
	
private:
	int const MICROSECONDS = 1000000;
	int cutTomatoTime;
	int cutCabbageTime;
	int cutBeefTime;
	int friedBeefTime;
	int deliverTime;
	int diningTime;
	int washPlateTime;
	int hamburgerWaitTime;
	
	static int numOfPlayers;
	
	void singlePlayer();
	
	void multiPlayer();
	
	
};
#endif /* player_hpp */
