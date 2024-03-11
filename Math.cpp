#include "Math.h"
#include <cstdio>
#include <stdarg.h>
#include <corecrt_malloc.h>
using namespace std;
int Math::Add(int x, int y) {
    return x + y;
};
int Math::Add(int x, int y, int z) {
    return x + y + z;
};
int Math::Add(double x, double y) {
    return x + y;
};
int Math::Add(double x, double y, double z) {
    return x + y + z;
};
int Math::Mul(int x, int y) {
    return x * y;
};
int Math::Mul(int x, int y, int z) {
    return x * y * z;
};
int Math::Mul(double x, double y) {
    return x * y;
};
int Math::Mul(double x, double y, double z) {
    return x * y * z;
};
int Math::Add(int count, ...) {
    int val = 0;
    va_list list;
    int i;
    va_start(list, count);
    for (i = 0; i < count; i++) {
        val += va_arg(list, int);
    }
    va_end(list);

    return val;
}; // sums up a list of integers
char* Math::Add(const char* v1, const char* v2)
{
    if (v1 == nullptr || v2 == nullptr) return nullptr;
    int num1 = 0, num2 = 0;
    for (int i = 0; v1[i] != '\0'; i++)
        num1 = num1 * 10 + v1[i] - '0';
    for (int i = 0; v2[i] != '\0'; i++)
        num2 = num2 * 10 + v2[i] - '0';
    int sum = num1 + num2;
    int sum2 = 0;
    while (sum != 0)
    {
        sum2 = sum2 * 10 + sum % 10;
        sum = sum / 10;
    }
    char* v3 = (char*)malloc(10 * sizeof(char));
    int i = 0;
    while (sum2 != 0)
    {
        v3[i] = sum2 % 10 + '0';
        sum2 = sum2 / 10;
        i++;
    }
    v3[i] = '\0';

    return v3;
}