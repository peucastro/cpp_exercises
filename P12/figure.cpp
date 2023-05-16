#include "Figure.h"
#include <iostream>
#include <vector>
using namespace std;

class Rectangle : public Figure
{
public:
    Rectangle(double x_center, double y_center, double width, double height) : Figure(x_center, y_center)
    {
        width_ = width;
        height_ = height;
    };

    virtual void draw() const { cout << "R(" << x_center_ << ',' << y_center_ << ")(" << width_ << ',' << height_ << ')'; }

protected:
    double width_;
    double height_;
};

class Circle : public Figure
{
public:
    Circle(double x_center, double y_center, double radius) : Figure(x_center, y_center) { radius_ = radius; }

    virtual void draw() const { cout << "C(" << x_center_ << ',' << y_center_ << ")(" << radius_ << ')'; }

protected:
    double radius_;
};

int main()
{
    {
        Rectangle r(10, 10, 200, 100);
        r.draw();
        cout << endl;
    }
    {
        Circle c(20, 20, 500);
        c.draw();
        cout << endl;
    }
    {
        Rectangle *r = new Rectangle(10, 10, 200, 100);
        r->draw();
        cout << endl;
        delete r;
    }
    {
        vector<Figure *> figures = {
            new Rectangle(10, 10, 200, 100),
            new Circle(20, 20, 500),
            new Rectangle(-10, -20, 150, 250),
            new Circle(0, 0, 100)};
        for (const auto &f : figures)
            f->draw();
        cout << endl;
        for (const auto &f : figures)
            delete f;
    }
    {
        vector<Figure *> figures = {
            new Rectangle(-10, -10, 5, 15),
            new Rectangle(0, 0, 20, 10),
            new Circle(5, 0, 25)};
        for (const auto &f : figures)
            f->draw();
        cout << endl;
        for (const auto &f : figures)
            delete f;
    }
    return 0;
}
