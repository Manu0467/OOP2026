#include "Volvo.h"

Volvo::Volvo()
{
	this->setFuelCapacity(60);
	this->setFuelConsumption(80);
	this->setAvgSpeed(60, 100, 50);
}

const char* Volvo::getName()
{
	return "Volvo";
}
