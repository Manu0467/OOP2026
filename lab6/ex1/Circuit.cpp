#include "Circuit.h"


Circuit::~Circuit()
{
	this->length = 0;
	for (int i = 0; i < cars.size(); i++)
	{
		delete cars[i];
	}
	for (int i = 0; i < didNotFinish.size(); i++)
	{
		delete didNotFinish[i];
	}
}

void Circuit::SetLength(int l)
{
	this->length = l ;
}

void Circuit::SetWeather(Weather n)
{
	this->w = n;
}

void Circuit::AddCar(Car* car)
{
	this->cars.push_back(car);
}

void Circuit::ShowFinalRanks()
{
	
	for (int i = 0; i < cars.size(); i++)
	{
		printf(" %s: %.2f \n", cars[i]->getName(), ranks[i]);
	}
	printf("\n");
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("These are the cars that did not have enough fuel to finish the race: ");
	for (int i = 0; i < didNotFinish.size(); i++)
	{
		printf("%s ", didNotFinish[i]->getName());
	}
	printf("\n");
}

void Circuit::Race()
{
	for (int i = 0; i < cars.size(); i++)
	{
		ranks.push_back(this->length / cars[i]->getAvgSpeed(this->w));
	}
	for (int i = 1; i < cars.size(); i++)
	{
		int p = i - 1;
		double aux = ranks[i];
		Car* auxc = cars[i];
		while (p >= 0 && ranks[p] > aux) {
			ranks[p+1] = ranks[p];
			cars[p + 1] = cars[p];
			p--;
		}
		ranks[p+1] = aux;
		cars[p + 1] = auxc;
	}
	for (int i = 0; i < cars.size(); i++)
	{
		double dist = cars[i]->getFuelConsumption()*(this->length/100);
		if (dist > this->length)
		{
			didNotFinish.push_back(cars[i]);
		}
	}
}
//5l/100km
//60 
//dist=60/5*100