//
//  order.hpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-22.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#ifndef order_hpp
#define order_hpp

#include <stdio.h>

enum
{
	ORDER_HAMBURGER	// order hamburger
};

class Order
{
	
public:
	Order(int, int = 2 * 60 + 30);
	~Order();
	
private:
	int const WAITE_TIME;	// default 37.5 * 4
	int food;
};
#endif /* order_hpp */
