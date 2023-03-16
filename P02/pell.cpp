#include <iostream>
using namespace std;

unsigned long pell(unsigned long n)
{
    unsigned long pn = 0;
    unsigned long p0 = 0;
    unsigned long p1 = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    for (unsigned long i = 1; i < n; i++)
    {
        pn = 2 * p1 + p0;
        p0 = p1;
        p1 = pn;
    }
    return pn;
}

int main()
{
    cout << pell(0) << '\n';
    cout << pell(1) << '\n';
    cout << pell(2) << '\n';
    cout << pell(3) << '\n';
    cout << pell(5) << '\n';
    cout << pell(50) << '\n';
    return 0;
}
