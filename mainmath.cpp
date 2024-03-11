#include <iostream>
#include "Math.h"
#include <cstdio>
int main()
{

    std::cout << Math::Add(7, 4);
    std::cout << std::endl;
    std::cout << Math::Add(7, 4, 2);
    std::cout << std::endl;
    std::cout << Math::Add(2.0, 4.0);
    std::cout << std::endl;
    std::cout << Math::Add(1.0, 3.0, 5.0);
    std::cout << std::endl;
    std::cout << Math::Mul(7, 4);
    std::cout << std::endl;
    std::cout << Math::Mul(7, 4, 2);
    std::cout << std::endl;
    std::cout << Math::Mul(7.0, 4.0);
    std::cout << std::endl;
    std::cout << Math::Mul(7.0, 1.0, 1.0);
    std::cout << std::endl;
    std::cout << Math::Add(4, 1, 2, 3, 4);
    std::cout << std::endl;
    const char* v1 = "300";
    const char* v2 = "1234";
    char* x = Math::Add(v1, v2);
    int y = Math::Add(5, 1, 2, 3, 4, 5);
    printf("%s ", x);
    std::cout << std::endl;
    printf("%d ", y);
    return 0;
}