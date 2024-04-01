#include "Fiat.h"
Fiat::Fiat() {
	capacity = 90;
	consumption = 15;
	rainSpeed = 43;
	sunnySpeed = 65;
	snowSpeed = 32;
	finished = false;
	time = 0;
};
Fiat::~Fiat() {
};
void Fiat::print() {
	std::cout << "Fiat";
};
void Fiat::printTime() {
	std::cout << time;
};
double Fiat::ComputeTime(Weather w, int l) {
	if (w == Weather::Rain)
		time = l / rainSpeed;
	else if (w == Weather::Sunny)
		time = l / sunnySpeed;
	else if (w == Weather::Snow)
		time = l / snowSpeed;
	return time;
};
bool Fiat::CanFinish(int l) {
	if (capacity > ((consumption / 100) * l))
		finished = true;
	return finished;
};