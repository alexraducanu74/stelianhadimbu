#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height)
{
    h = height;
    w = width;
    this->m = new char* [height];
    for (int i = 0; i < height; ++i)
    {
        m[i] = new char[width];
        for (int j = 0; j < width; ++j)
        {
            m[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < h; ++i)
    {
        delete[] m[i];
    }
    delete[] m;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {

            int dx = i - x;
            int dy = j - y;
            double distance = sqrt(dx * dx + dy * dy);

            if (abs(distance - ray) < 0.5)
            {
                m[i][j] = ch;
            }
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {

            int dx = i - x;
            int dy = j - y;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance <= ray)
            {
                m[i][j] = ch;
            }
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
        if (i >= 0 && i < h)
        {
            if (left >= 0 && left < w)
                m[i][left] = ch;
            if (right >= 0 && right < w)
                m[i][right] = ch;
        }
    for (int j = left; j <= right; j++)
        if (j >= 0 && j < w)
        {
            if (top >= 0 && top < h)
                m[top][j] = ch;
            if (bottom >= 0 && bottom < h)
                m[bottom][j] = ch;
        }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top + 1; i < bottom; i++)
        for (int j = left + 1; j < right; j++)
            if (i >= 0 && i < h && j >= 0 && j < w)
                m[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < w && y >= 0 && y < h)
        m[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        m[y1][x1] = ch;
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            printf("%c ", m[i][j]);
        printf("\n");
    }
}
void Canvas::Clear()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            m[i][j] = ' ';
}
