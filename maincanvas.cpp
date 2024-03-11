#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas c(20, 20);
    printf("Point:\n");
    c.SetPoint(7, 4, 'c');
    c.Print();
    printf("Line\n");
    c.Clear();
    c.DrawLine(0, 0, 7, 7, 'a');
    c.Print();
    printf("Rect\n");
    c.Clear();
    c.DrawRect(2, 3, 4, 6, 'a');
    c.FillRect(2, 3, 4, 6, 'b');
    c.Print();
    printf("Cerc\n");
    c.Clear();
    c.DrawCircle(10, 10, 6, 'a');
    c.FillCircle(10, 10, 6, 'b');
    c.Print();
    
    

}
