#pragma once
#include <iostream>
#include "Weather.h"
class Car
{
protected:

	double capacity;
	double consumption;
	double rainSpeed;
	double sunnySpeed;
	double snowSpeed;
	bool finished;
	double time;
public:
	Car() {};
	~Car() {};
	virtual double ComputeTime(Weather w, int l) = 0;
	virtual bool CanFinish(int l) = 0;
	virtual void print() {};
	virtual void printTime() {};
};

