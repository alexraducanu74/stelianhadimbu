#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>
#include <vector>
#include <initializer_list>

Sort::Sort(int nr_elem, int min, int max) {
	count = nr_elem;
	v = new int[nr_elem];
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < nr_elem; i++)
		v[i] = min + rand() % (min - max + 1);
	size = count;
}
Sort::Sort(int* vector, int nr_elem) {
	count = nr_elem;
	v = new int[nr_elem];
	for (int i = 0; i < nr_elem; i++)
		v[i] = vector[i];
	size = count;
}
Sort::Sort(int nr_elem, ...) {
	count = nr_elem;
	v = new int[nr_elem];
	va_list vl;
	va_start(vl, nr_elem);
	for (int i = 0; i < nr_elem; i++)
		v[i] = va_arg(vl, int);
	va_end(vl);
	size = count;
}
Sort::Sort(char* c) {
	v = new int[strlen(c)];
	int nr_curent = 0;
	char* p = strtok(c, ",");
	int idx = 0;
	while (p) {
		nr_curent = 0;
		for (int i = 0; i < strlen(p); i++)
			nr_curent = nr_curent * 10 + p[i] - '0';
		v[idx] = nr_curent;
		idx++;
		p = strtok(NULL, ",");
	}
	count = idx;
	size = count;
}
Sort::Sort(std::initializer_list<int> init){
	count = init.size();
	v = new int[count];
	int i = 0;
	for (auto it=init.begin(); it != init.end(); ++it)
		v[i++] = *it;
	size = count;
};
void Sort::Print() {
	for (int i = 0; i < count; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
int Sort::GetElementsCount()
{
	return count;
}
int Sort::GetElementFromIndex(int index) {
	return v[index];
}
void Sort::InsertSort(bool ascendent) {

	for (int i = 1; i < count; ++i) {
		int key = v[i];
		int j = i - 1;

		// Move elements of arr[0..i-1], that are
		// greater (or less if descending) than key, to one position ahead
		// of their current position
		if (ascendent) {
			while (j >= 0 && v[j] > key) {
				v[j + 1] = v[j];
				--j;
			}
		}
		else {
			while (j >= 0 && v[j] < key) {
				v[j + 1] = v[j];
				--j;
			}
		}
		v[j + 1] = key;
	}
}
Sort::~Sort() {
	delete[] v;
}
int Sort::partition(int low, int high, bool ascending) {
	int pivot = v[high];
	int i = low - 1;

	for (int j = low; j < high; ++j) {
		if (ascending ? v[j] <= pivot : v[j] >= pivot) {
			++i;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[high]);
	return i + 1;
}
// Function to implement QuickSort
void Sort::quickSort(int low, int high, bool ascending) {
	if (low < high) {
		int pi = partition(low, high, ascending);
		quickSort(low, pi - 1, ascending);
		quickSort(pi + 1, high, ascending);
	}
}
// Wrapper function for quickSort with default parameters
void Sort::QuickSort(bool ascendent) {
	quickSort(0, count - 1, ascendent);
}
void Sort::swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void Sort::BubbleSort(bool ascendent) {
	for (int i = 0; i < count - 1; ++i)
		for (int j = 0; j < count - i - 1; ++j)
			if (ascendent ? v[j] > v[j + 1] : v[j] < v[j + 1])
				swap(v[j], v[j + 1]);
}
void Sort::AddElement(const int& elem) {
	if(count+1<size)
	{
		v[count] = elem;
		count++;
	}
	else 
	{
		v = (int*)(realloc(v, (count * 2) * sizeof(int)));
		v[count] = elem;
		count++;
		size *= 2;
	}
};
void Sort::RemoveElement(const int& elem) {
	bool ok = false;
	int i = 0;
	for(i = 0;i < count;i ++)
		if (v[i] == elem && i != count-1)
		{
			ok = true;
			break;
		}
	if(ok)
	{
		for (int j = i; j < count - 1; j++)
			v[i] = v[i + 1];
	}
	
	if(ok)
	count--;
};