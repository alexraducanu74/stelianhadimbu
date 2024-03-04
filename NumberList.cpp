#pragma once
#include "NumberList.h"
#include <iostream>
void NumberList::Init() {
	count = 0;
}        // count will be 0
bool NumberList::Add(int x)
{
    if (count >= 10)
        return false;
    numbers[count] = x;
    count++;
    return true;
    
}   // adds X to the numbers list and increase the data member count.
// if count is bigger or equal to 10, the function will return false
void NumberList::Sort()
{
    int i, j;
    int aux = 0;
    bool swapped;
    for (i = 0; i < count - 1; i++) {
        swapped = false;
        for (j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
               
                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
                swapped = true;
            }
        }


        if (swapped == false)
            break;
    
    }
}          // will sort the numbers vector
void NumberList::Print() {
for(int i = 0; i < count ; i ++)
{
	std::cout <<numbers[i] << " ";
}
}