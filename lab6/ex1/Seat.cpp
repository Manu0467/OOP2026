#include "Seat.h"

Seat::Seat()
{
	this->setAvgSpeed(50, 80, 40);
	this->setFuelCapacity(65);
	this->setFuelConsumption(7);
}

const char* Seat::getName()
{
	return "Seat";
}
