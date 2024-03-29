#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <initializer_list>
#include <vector>
int main()
{

    Sort s(10, 10, 100);
    s.Print();
    s.InsertSort(true);
    s.Print();
    std::cout << "----------------------------------" << std::endl;
    int v[5] = { 1,2,3,74,5 };
    Sort s2(v, 5);
    s2.Print();
    s2.QuickSort();
    s2.Print();
    std::cout << "----------------------------------" << std::endl;
    Sort s3(6, 1, 2, 3, 74, 75, 76);
    s3.Print();
    s3.BubbleSort();
    s3.Print();
    std::cout << "----------------------------------" << std::endl;
    char c[] = "12,34,74,15";
    Sort s4(c);
    s4.Print();
    s4.BubbleSort(true);
    s4.Print();
    std::cout << "----------------------------------" << std::endl;
    Sort s5({1,7,5});
    s5.Print();
    s5.QuickSort();
    s5.Print();
    s5.AddElement(20);
    s5.Print();
    s3.RemoveElement(22);
    s3.Print();
}