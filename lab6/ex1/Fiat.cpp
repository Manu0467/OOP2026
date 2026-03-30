#include "Fiat.h"

Fiat::Fiat()
{
	this->setAvgSpeed(70, 80, 50);
	this->setFuelCapacity(40);
	this->setFuelConsumption(5);
}

const char* Fiat::getName()
{
	return "Fiat";
}
