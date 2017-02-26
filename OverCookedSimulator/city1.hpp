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
#include <vector>
#include "order.hpp"

class City1
{
public:
	City1(int = 300);
	~City1();
	
	void startGame();
	bool isGameOver();
	std::vector<Order> getCity1Orders();
	void orderDelivered(int);
	void printTotalRevenue();
	void printOrders();
	void printIngredients();
	
	bool useCuttedBeef();
	bool useFriedBeef();
	bool useCuttedCabbage();
	bool useCuttedTomato();
	bool useCleanPlate();
	bool useDirtyPlate();
	
	void addCuttedBeef()	{ cuttedBeef++; }
	void addFriedBeef()		{ friedBeef++; }
	void addCuttedCabbage()	{ cuttedCabbage++; }
	void addCuttedTomato()	{ cuttedTomato++; }
	void addCleanPlate()	{ cleanPlate++; }
	void addDirtyPlate()	{ dirtyPlate++; }
	
	bool hasCuttedBeef()	{ return cuttedBeef > 0; }
	bool hasFriedBeef()		{ return friedBeef > 0; }
	bool hasCuttedCabbage()	{ return cuttedCabbage > 0; }
	bool hasCuttedTomato()	{ return cuttedTomato > 0; }
	bool hasCleanPlate()	{ return cleanPlate > 0; }
	bool hasDirtyPlate()	{ return dirtyPlate > 0; }
	
	int getCuttedBeef()		{ return cuttedBeef; }
	int getFriedBeef()		{ return friedBeef; }
	int getCuttedCabbage()	{ return cuttedCabbage; }
	int getCuttedTomato()	{ return cuttedTomato; }
	int getCleanPlate()		{ return cleanPlate; }
	int getDirtyPlate()		{ return dirtyPlate; }
	
	void setCuttedBeef(int cuttedBeef)			{ this->cuttedBeef = cuttedBeef; }
	void setFriedBeef(int friedBeef)			{ this->friedBeef = friedBeef; }
	void setCuttedCabbage(int cuttedCabbage)	{ this->cuttedCabbage = cuttedCabbage; }
	void setCuttedTomato(int cuttedTomato)		{ this->cuttedTomato = cuttedTomato; }
	void setCleanPlate(int cleanPlate)			{ this->cleanPlate = cleanPlate; }
	void setDirtyPlate(int dirtyPlate)			{ this->dirtyPlate = dirtyPlate; }
	
private:
	int const ORDER_SIZE = 4;
	int const CITY1_TIME_LIMIT;	// default 300s
	
	bool gameStarted;
	
	int cuttedTomato;
	int cuttedCabbage;
	int cuttedBeef;
	int friedBeef;
	int cleanPlate;
	int dirtyPlate;
	
	int ordersDelivered;
	int tips;
	int ordersFailed;
	int total;
	
	std::vector<Order> city1Orders;
	std::thread tCountdown;
	std::thread tMakeOrders;
	
	void makeOrders();
	void countdown(int);
};

#endif /* city1_hpp */
