#include "Point.h"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::show() const
{
    std::cout << '(' << this->x << ',' << this->y << ')';
}

double Point::distance_to(Point p) const
{
    return sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y));
}
