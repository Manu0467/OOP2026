#include "BMW.h"

BMW::BMW()
{
	this->setAvgSpeed(65, 125, 50);
	this->setFuelCapacity(100);
	this->setFuelConsumption(20);
}

const char* BMW::getName()
{
	return "BMW";
}
