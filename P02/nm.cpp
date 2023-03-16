#include <iostream>
using namespace std;

unsigned long pw(unsigned long n)
{
    if (n == 0)
        return 1;
    unsigned long result = 2;
    for (unsigned long i = 0; i < n - 1; i++)
    {
        result *= 2;
    }
    return result;
}

unsigned long next_mersenne(unsigned long n)
{
    int i = 0;
    while (pw(i) - 1 < n)
    {
        i += 1;
    }
    return pw(i) - 1;
}

int main()
{
    cout << next_mersenne(0) << '\n';
    cout << next_mersenne(1) << '\n';
    cout << next_mersenne(2) << '\n';
    cout << next_mersenne(4) << '\n';
    cout << next_mersenne(128) << '\n';
    cout << next_mersenne(4294967296UL) << '\n';
    return 0;
}
