#pragma once
#include "Car.h" 
class RangeRover : public Car
{
public:
	RangeRover();
	~RangeRover();
	void print();
	void printTime();
	double ComputeTime(Weather w, int l);
	bool CanFinish(int l);
};

