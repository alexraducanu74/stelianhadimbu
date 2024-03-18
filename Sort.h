#pragma once
#include <initializer_list>
class Sort
{
    int* v;
    int count=0;
    int size = 0;
public:

    Sort(int nr_elem, int min, int max);
    Sort(int* vector, int nr_elem);
    Sort(int count, ...);
    Sort(char* c);
    Sort(std::initializer_list<int> init);
    ~Sort();
    static void swap(int& a, int& b);
    void InsertSort(bool ascendent = false);
    void AddElement(const int& elem);
    void RemoveElement(const int& elem);
    int partition(int low, int high, bool ascending);
    void quickSort(int low, int high, bool ascending);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};