#include "Shape.h"
#include <cmath>
using namespace std;

class Circle : public Shape
{
public:
    Circle(const point &center, const double &radius) : Shape(center) { radius_ = radius; }

    virtual double area() const { return pow(radius_, 2) * M_PI; }

    virtual double perimeter() const { return 2 * M_PI * radius_; }

    virtual bool contains(const point &p) const { return p.x >= get_center().x + radius_ || p.x <= get_center().x - radius_ || p.y >= get_center().y + radius_ || p.y <= get_center().y - radius_ ? 0 : 1; }

private:
    double radius_;
};

class Rectangle : public Shape
{
public:
    Rectangle(const point &center, const double &width, const double &height) : Shape(center)
    {
        width_ = width;
        height_ = height;
    }

    virtual double area() const { return width_ * height_; }

    virtual double perimeter() const { return 2.0 * (width_ + height_); }

    virtual bool contains(const point &p) const { return p.x < get_center().x + width_ / 2.0 && p.x > get_center().x - width_ / 2.0 && p.y < get_center().y + height_ / 2.0 && p.y > get_center().y - height_ / 2.0 ? 1 : 0; }

private:
    double width_;
    double height_;
};

int main()
{
    {
        Circle c({1.0, 2.0}, 1.0);
        const point &p = c.get_center();
        cout << fixed << setprecision(2)
             << '(' << p.x << ',' << p.y << ')' << ' '
             << c.area() << ' ' << c.perimeter() << '\n';
    }
    {
        Rectangle r({3.4, 4.5}, 1, 2);
        const point &p = r.get_center();
        cout << fixed << setprecision(2)
             << '(' << p.x << ',' << p.y << ')' << ' '
             << r.area() << ' ' << r.perimeter() << '\n';
    }
    {
        const Shape &s1 = Circle({1, 2}, 3);
        const Shape &s2 = Rectangle({4, 5}, 6, 7);
        cout << fixed << setprecision(2) << boolalpha
             << s1.area() << ' ' << s1.perimeter() << ' '
             << s1.contains({1, 2}) << ' ' << s1.contains({4, 5}) << ' '
             << s2.area() << ' ' << s2.perimeter() << ' '
             << s2.contains({1, 2}) << ' ' << s2.contains({4, 5}) << '\n';
    }
    {
        Circle c({1, 2}, 3);
        point a[]{
            {-2.1, 2.0}, {-1.9, 2.0}, {4.1, 2.0}, {3.9, 2.0}, {1.0, 4.9}, {1.0, -0.9}, {1.0, 5.1}, {1.0, -1.1}, {1.2, -0.3}, {5.2, 5.1}, {2.1, -0.5}, {3.2, 5.5}};
        cout << fixed << setprecision(2);
        for (point &p : a)
            if (c.contains(p))
                cout << '(' << p.x << ',' << p.y << ')';
        cout << '\n';
    }
    {
        Rectangle r({1, 2}, 6, 8);
        point a[]{
            {-2.1, 2.0}, {-1.9, 2.0}, {4.1, 2.0}, {3.9, 2.0}, {1.0, 4.9}, {1.0, -0.9}, {1.0, 5.1}, {1.0, -1.1}, {1.2, -0.3}, {5.2, 5.1}, {2.1, -0.5}, {3.2, 5.5}};
        cout << fixed << setprecision(1);
        for (point &p : a)
            if (r.contains(p))
                cout << '(' << p.x << ',' << p.y << ')';
        cout << '\n';
    }

    return 0;
}
