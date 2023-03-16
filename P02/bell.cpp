#include <iostream>
using namespace std;

unsigned long fact(unsigned long num)
{
    unsigned long ans = 1;
    for (unsigned long i = 1; i <= num; i++)
    {
        ans *= i;
    }
    return ans;
}

unsigned long bc(unsigned long n, unsigned long k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

unsigned long bell(unsigned long n)
{
    if (n < 2)
        return 1;

    unsigned long ans = 0;

    for (unsigned long i = 0; i < n; i++)
        ans += bc(n - 1, i) * bell(i);
    return ans;
}

int main()
{
    cout << bell(0) << '\n';
    cout << bell(1) << '\n';
    cout << bell(2) << '\n';
    cout << bell(3) << '\n';
    cout << bell(4) << '\n';
    cout << bell(6) << '\n';
    return 0;
}
