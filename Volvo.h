#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo();
	~Volvo();
	void print();
	void printTime();
	double ComputeTime(Weather w, int l);
	bool CanFinish(int l);
};

