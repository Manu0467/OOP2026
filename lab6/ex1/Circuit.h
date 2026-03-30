#pragma once
#include "Car.h"
#include <vector>
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Volvo.h"

class Circuit
{
    std::vector<Car*>cars;
	int length;	
	Weather w;
	std::vector<double>ranks;
	std::vector<Car*>didNotFinish;

public:
	~Circuit();
	void SetLength(int l);
	void SetWeather(Weather n);
	void AddCar(Car* car);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Race();
	
};

