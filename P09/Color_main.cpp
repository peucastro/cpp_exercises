#include "Color.h"
#include <iostream>
using namespace std;

int main()
{
    {
        Color c(1, 2, 3);
        const Color &r = c;
        cout << (int)r.red() << ' '
             << (int)r.green() << ' '
             << (int)r.blue() << ' '
             << boolalpha << r.equal_to(r) << '\n';
    }
    {
        cout << boolalpha
             << Color::WHITE.equal_to(Color::WHITE) << ' '
             << Color::BLACK.equal_to(Color::RED) << ' '
             << Color::BLUE.equal_to(Color::GREEN) << '\n';
    }
    {
        Color c(Color::WHITE);
        cout << (int)c.red() << ' '
             << (int)c.green() << ' '
             << (int)c.blue() << ' '
             << boolalpha << c.equal_to(Color::WHITE) << ' '
             << c.equal_to(Color::BLACK) << '\n';
    }
    {
        Color c(Color::WHITE);
        c.invert();
        cout << (int)c.red() << ' '
             << (int)c.green() << ' '
             << (int)c.blue() << ' '
             << boolalpha << c.equal_to(Color::WHITE) << ' '
             << c.equal_to(Color::BLACK) << '\n';
    }
    {
        Color c(255, 128, 12);
        c.invert();
        Color c2(c);
        c2.invert();
        cout << (int)c.red() << ' '
             << (int)c.green() << ' '
             << (int)c.blue() << ' '
             << boolalpha << c.equal_to({0, 127, 243}) << ' '
             << (int)c2.red() << ' '
             << (int)c2.green() << ' '
             << (int)c2.blue() << ' '
             << boolalpha << c2.equal_to({255, 128, 12}) << '\n';
    }
    return 0;
}
