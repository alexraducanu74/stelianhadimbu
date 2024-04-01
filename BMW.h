#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	~BMW();
	void print();
	void printTime();
	double ComputeTime(Weather w, int l);
	bool CanFinish(int l);
};

