//
//  order.hpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-22.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#ifndef order_hpp
#define order_hpp

/// todo later, this class should be a parent class
/// inherited by class like OrderHamburger
enum
{
	ORDER_HAMBURGER,	// order hamburger
	ORDER_HAMBURGER1 = 1100,	// order hamburger with beef
	ORDER_HAMBURGER2 = 1110,	// order hamburger1 with cabbage
	ORDER_HAMBURGER3 = 1111		// order hamburger2 with tomato
};

class Order
{
	
public:
	static int getNumOfOrders() { return numOfOrders; }
	
	Order(int = ORDER_HAMBURGER, int = 2 * 60 + 30);
	~Order();
	
	int makeOrder();
	int getOrder();
	bool orderExpired();
	void printOrder();
	
private:
	int const WAITE_TIME;	// default 37.5 * 4
	static int numOfOrders;
	
	int food;
	int foodKind;
	
	double startTime;
};
#endif /* order_hpp */

















