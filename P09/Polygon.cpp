#include "Polygon.h"

Polygon::Polygon()
{
    this->poly = {};
}

Polygon::Polygon(std::vector<Point> poly)
{
    this->poly = poly;
}

bool Polygon::get_vertex(int n, Point &p) const
{
    size_t pos = n - 1;
    if (pos < this->poly.size())
    {
        p = this->poly[pos];
        return true;
    }
    return false;
}

void Polygon::add_vertex(const int n, Point p)
{
    this->poly.insert(this->poly.begin() + n - 1, p);
}

void Polygon::show() const
{
    std::cout << '{';
    for (Point p : this->poly)
        p.show();
    std::cout << '}';
}

double Polygon::perimeter() const
{
    double ans = 0;
    for (size_t i = 0; i < this->poly.size() - 1; i++)
    {
        ans += this->poly[i].distance_to(this->poly[i + 1]);
    }
    ans += this->poly[poly.size() - 1].distance_to(poly[0]);
    return ans;
}
