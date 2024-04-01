#include "Seat.h"
Seat::Seat() {
	capacity = 74;
	consumption = 8;
	rainSpeed = 20;
	sunnySpeed = 80;
	snowSpeed = 15;
	finished = false;
	time = 0;
};
Seat::~Seat() {
};
void Seat::print() {
	std::cout << "Seat";
};
void Seat::printTime() {
	std::cout << time;
};
double Seat::ComputeTime(Weather w, int l) {
	if (w == Weather::Rain)
		time = l / rainSpeed;
	else if (w == Weather::Sunny)
		time = l / sunnySpeed;
	else if (w == Weather::Snow)
		time = l / snowSpeed;
	return time;
};
bool Seat::CanFinish(int l) {
	if (capacity > ((consumption / 100) * l))
		finished = true;
	return finished;
};