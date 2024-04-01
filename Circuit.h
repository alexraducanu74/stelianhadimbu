#pragma once
#include <stdlib.h>
#include "Car.h"
#include "Weather.h"
class Circuit
{
private:
	Car** cars;
	int size;
	int count;
	int length;
	Weather weather;

public:
	Circuit();
	~Circuit();
	void SetLength(int l);
	void SetWeather(Weather w);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	void ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
};

