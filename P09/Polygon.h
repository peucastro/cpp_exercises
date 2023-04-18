#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include "Point.h"

class Polygon
{
public:
    Polygon();
    Polygon(std::vector<Point>);
    bool get_vertex(int n, Point &p) const;
    void add_vertex(const int n, Point p);
    void show() const;
    double perimeter() const;

private:
    std::vector<Point> poly;
};

#endif
