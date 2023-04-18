#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point
{
public:
    Point();
    Point(int x, int y);
    void show() const;
    double distance_to(Point p) const;

private:
    int x;
    int y;
};

#endif
