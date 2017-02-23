//
//  city1.hpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-17.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#ifndef city1_hpp
#define city1_hpp

#include <thread>

class City1
{
public:
	City1(int = 300);
	~City1();
	
	void startGame();
	bool isGameOver();
	
	bool useCuttedTomato();
	bool useCuttedCabbage();
	bool useCuttedBeef();
	bool useFriedBeef();
	bool useCleanPlate();
	bool useDirtyPlate();
	
	void addCuttedTomato()	{ cuttedTomato++; }
	void addCuttedCabbage()	{ cuttedCabbage++; }
	void addCuttedBeef()	{ cuttedBeef++; }
	void addFriedBeef()		{ friedBeef++; }
	void addCleanPlate()	{ cleanPlate++; }
	void addDirtyPlate()	{ dirtyPlate++; }
	
	bool hasCuttedTomato()	{ return cuttedTomato > 0; }
	bool hasCuttedCabbage()	{ return cuttedCabbage > 0; }
	bool hasCuttedBeef()	{ return cuttedBeef > 0; }
	bool hasFriedBeef()		{ return friedBeef > 0; }
	bool hasCleanPlate()	{ return cleanPlate > 0; }
	bool hasDirtyPlate()	{ return dirtyPlate > 0; }
	
	int getCuttedTomato()	{ return cuttedTomato; }
	int getCuttedCabbage()	{ return cuttedCabbage; }
	int getCuttedBeef()		{ return cuttedBeef; }
	int getFriedBeef()		{ return friedBeef; }
	int getCleanPlate()		{ return cleanPlate; }
	int getDirtyPlate()		{ return dirtyPlate; }
	
	void setCuttedTomato(int cuttedTomato)		{ this->cuttedTomato = cuttedTomato; }
	void setCuttedCabbage(int cuttedCabbage)	{ this->cuttedCabbage = cuttedCabbage; }
	void setCuttedBeef(int cuttedBeef)			{ this->cuttedBeef = cuttedBeef; }
	void setFriedBeef(int friedBeef)			{ this->friedBeef = friedBeef; }
	void setCleanPlate(int cleanPlate)			{ this->cleanPlate = cleanPlate; }
	void setDirtyPlate(int dirtyPlate)			{ this->dirtyPlate = dirtyPlate; }
	
private:
	int const CITY1_TIME_LIMIT;	// default 300s
	
	bool gameStarted;
	
	int cuttedTomato;
	int cuttedCabbage;
	int cuttedBeef;
	int friedBeef;
	int cleanPlate;
	int dirtyPlate;
	
	std::thread tCountdown;
	std::thread tMakeOrders;
	
	void makeOrders();
	void countdown(int);
};

#endif /* city1_hpp */
