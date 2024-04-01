#include "BMW.h"
BMW::BMW() {
	capacity = 100;
	consumption = 10;
	rainSpeed  = 40;
	sunnySpeed = 60;
	snowSpeed = 30;
	finished = false;
	time = 0;
};
BMW::~BMW() {
};
void BMW::print() {
	std::cout << "BMW";
};
void BMW::printTime() {
	std::cout << time;
};
double BMW::ComputeTime(Weather w, int l) {
	if (w == Weather::Rain)
		time = l / rainSpeed;
	else if (w == Weather::Sunny)
		time = l / sunnySpeed;
	else if (w == Weather::Snow)
		time = l / snowSpeed;
	return time;
};
bool BMW::CanFinish(int l) {
	if (capacity > ((consumption / 100) * l))
		finished = true;
	return finished;
};