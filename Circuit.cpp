#include "Circuit.h"
Circuit::Circuit() {
	count = 0;
	size = 100;
	cars = (Car**)(malloc(size * sizeof(Car*)));
};
Circuit::~Circuit() {
	delete[] cars;
};
void Circuit::SetLength(int l) {
	length = l;
};
void Circuit::SetWeather(Weather w) {
	weather = w;
};
void Circuit::AddCar(Car* c) {
	if(count + 1< size)
	{
		cars[count] = c;
		count++;
	}
	else
	{
		cars = (Car**)(realloc(cars, (count * 2) * sizeof(Car)));
		cars[count] = c;
		count++;
		size *= 2;
	}
};
void swap(Car* &a, Car* &b) {
	Car* aux;
	aux = a;
	a = b;
	b = aux;
}
void Circuit::Race() {
	for (int i = 0; i < count; i++)
		if (cars[i]->CanFinish(length))
			cars[i]->ComputeTime(weather, length);
	for (int i = 0; i < count; i++) {
		bool swapped = false;
		for (int j = 0; j < count - i - 1; j++) {
			if (cars[j]->ComputeTime(weather, length) > cars[j + 1]->ComputeTime(weather, length)) {
				swap(cars[j], cars[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
};
void Circuit::ShowFinalRanks() {
	for (int i = 0; i < count; i++)
		if(cars[i]->CanFinish(length))
	{
		cars[i]->print();
		std::cout << " ";
		cars[i]->printTime();
		std::cout << std::endl;
	}
}; // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < count; i++)
		if (!cars[i]->CanFinish(length))
		{
			cars[i]->print();
			std::cout << std::endl;
		}
}; // it is possible that some cars don't have enough fuel to finish the circuit