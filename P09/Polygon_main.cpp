#include <iomanip>
#include "Polygon.h"
using namespace std;

int main()
{
    {
        Point p1, p2(0, 1);
        p1.show();
        p2.show();
        cout << '\n';
    }
    {
        Polygon poly1;
        Point p1, p2(0, 1), p3(1, 0);
        Polygon poly2(vector<Point>{p1, p2, p3});
        poly1.show();
        cout << " ";
        poly2.show();
        cout << '\n';
    }
    {
        Point p1, p2(0, 1), p3(1, 0);
        Polygon poly1(vector<Point>{p1, p2, p3});
        cout << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n';
    }
    {
        Point p1, p2(0, 1), p3(1, 0);
        Polygon poly1(vector<Point>{p1, p2, p3});
        Point p;
        if (poly1.get_vertex(2, p))
        {
            p.show();
            cout << ' ';
        }
        else
            cout << "vertex not found! ";
        if (poly1.get_vertex(0, p))
        {
            p.show();
            cout << ' ';
        }
        else
            cout << "vertex not found! ";
        cout << '\n';
    }
    {
        Point p1, p2(0, 1), p3(1, 0), p4(1, 1);
        Polygon poly1 = vector<Point>{p1, p2, p3};
        poly1.add_vertex(3, p4);
        poly1.show();
        cout << ' ' << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n';
    }
    {
        Point p1(2, 5), p2;
        p1.show();
        p2.show();
        cout << '\n';
    }
    {
        Point p1(1, 2), p2(2, 3), p3(4, 5);
        Polygon poly1 = vector<Point>{p1, p2, p3};
        Polygon poly2;
        poly1.show();
        poly2.show();
        cout << '\n';
    }
    {
        Point p1(1, 1), p2(1, 2), p3(2, 1), p4(3, 0);
        Polygon poly1 = vector<Point>{p1, p2, p3, p4};
        poly1.show();
        cout << ' ' << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n';
    }
    {
        Point p1(1, 1), p2(1, 2), p3(2, 1), p4(3, 0);
        Polygon poly1 = vector<Point>{p1, p2, p3, p4};
        Point p;
        if (poly1.get_vertex(5, p))
        {
            p.show();
            cout << ' ';
        }
        else
            cout << "vertex not found! ";
        if (poly1.get_vertex(4, p))
        {
            p.show();
            cout << ' ';
        }
        else
            cout << "vertex not found! ";
        cout << '\n';
    }
    return 0;
}
