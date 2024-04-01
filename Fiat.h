#pragma once
#include "Car.h"  
class Fiat : public Car
{
public:
	Fiat();
	~Fiat();
	void print();
	void printTime();
	double ComputeTime(Weather w, int l);
	bool CanFinish(int l);
};

