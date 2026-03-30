#pragma once
#include "Weather.h"
class Car
{
protected:
	double fuelCapacity,
		fuelConsumption,
		avgSpeed[3];
	char name[300];
public:
	virtual const char* getName() = 0;
	virtual void setFuelCapacity(int fuel) {
		this->fuelCapacity = fuel;
	}
	virtual void setFuelConsumption(int  f) {
		this->fuelConsumption = f;
	}
	virtual void setAvgSpeed(int rain, int sunny, int snow) {
		avgSpeed[Rain] = rain;
		avgSpeed[Sunny] = sunny;
		avgSpeed[Snow] = snow;
	}
	virtual double getFuelCapacity() {
		return this->fuelCapacity;
	}
	virtual double getFuelConsumption() {
		return this->fuelConsumption;
	}
	virtual double getAvgSpeed(Weather n) {
	
		return this->avgSpeed[n];
	}
};

