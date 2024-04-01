#include "Volvo.h"
Volvo::Volvo() {
	capacity = 150;
	consumption = 25;
	rainSpeed = 72;
	sunnySpeed = 52;
	snowSpeed = 24;
	finished = false;
	time = 0;
};
Volvo::~Volvo() {
};
void Volvo::print() {
	std::cout << "Volvo";
};
void Volvo::printTime() {
	std::cout << time;
};
double Volvo::ComputeTime(Weather w, int l) {
	if (w == Weather::Rain)
		time = l / rainSpeed;
	else if (w == Weather::Sunny)
		time = l / sunnySpeed;
	else if (w == Weather::Snow)
		time = l / snowSpeed;
	return time;
};
bool Volvo::CanFinish(int l) {
	if (capacity > ((consumption / 100) * l))
		finished = true;
	return finished;
};