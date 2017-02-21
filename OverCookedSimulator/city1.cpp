//
//  city1.cpp
//  OverCookedSimulator
//
//  Created by Will on 2017-02-17.
//  Copyright © 2017 Muscle Ye. All rights reserved.
//

#include "city1.hpp"

City1::City1()
{
	setCuttedTomato(0);
	setCuttedCabbage(0);
	setCuttedBeef(0);
	setFriedBeef(0);
	setCleanPlate(2);
	setDirtyPlate(0);
}

bool City1::useCuttedTomato()
{
	if (!hasCuttedTomato())
		return false;
	else
		cuttedTomato--;
	return true;
}

bool City1::useCuttedCabbage()
{
	if (!hasCuttedCabbage())
		return false;
	else
		cuttedCabbage--;
	return true;
}

bool City1::useCuttedBeef()
{
	if (!hasCuttedBeef())
		return false;
	else
		cuttedBeef--;
	return true;
}

bool City1::useFriedBeef()
{
	if (!hasFriedBeef())
		return false;
	else
		friedBeef--;
	return true;
}

bool City1::useCleanPlate()
{
	if (!hasCleanPlate())
		return false;
	else
		cleanPlate--;
	return true;
}

bool City1::useDirtyPlate()
{
	if (!hasDirtyPlate())
		return false;
	else
		dirtyPlate--;
	return true;
}








