#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	~Seat();
	void print();
	void printTime();
	double ComputeTime(Weather w, int l);
	bool CanFinish(int l);
};

