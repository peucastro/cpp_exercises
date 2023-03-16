#include "complex.h"
#include <math.h>

void add(const complex &a, const complex &b, complex &r)
{
    r = {a.x + b.x, a.y + b.y};
}

void mul(const complex &a, const complex &b, complex &r)
{
    r = {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}

double norm(const complex &c)
{
    return sqrt(pow(c.x, 2) + pow(c.y, 2));
}

int main()
{
    complex a{2, 0}, b{2.5, -3.1}, s, m;
    add(a, b, s);
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
    return 0;
}
