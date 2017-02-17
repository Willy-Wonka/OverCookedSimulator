//
//  main.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-17.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[])
{
	double x = 31415.9265, fractional, integer;
	fractional = modf(x, &integer);
	printf("%.4lf = %.4lf + %.4lf\n", x, integer, fractional);
		
	// insert code here...
	cout << "Hello, World!\n";
    return 0;
}
