#include "RangeRover.h"
RangeRover::RangeRover() {
	capacity = 120;
	consumption = 20;
	rainSpeed = 50;
	sunnySpeed = 70;
	snowSpeed = 45;
	finished = false;
	time = 0;
};
RangeRover::~RangeRover() {
};
void RangeRover::print() {
	std::cout << "RangeRover";
};
void RangeRover::printTime() {
	std::cout << time;
};
double RangeRover::ComputeTime(Weather w, int l) {
	if (w == Weather::Rain)
		time = l / rainSpeed;
	else if (w == Weather::Sunny)
		time = l / sunnySpeed;
	else if (w == Weather::Snow)
		time = l / snowSpeed;
	return time;
};
bool RangeRover::CanFinish(int l) {
	if (capacity > ((consumption / 100) * l))
		finished = true;
	return finished;
};