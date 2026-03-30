#include "RangeRover.h"

RangeRover::RangeRover()
{
	this->setAvgSpeed(80, 120, 60);
	this->setFuelCapacity(85);
	this->setFuelConsumption(15);
}

const char* RangeRover::getName()
{
	return "RangeRover";
}
