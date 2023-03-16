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

int main()
{
    cout << bc(5, 0) << '\n';
    cout << bc(5, 1) << '\n';
    cout << bc(5, 5) << '\n';
    cout << bc(5, 2) << '\n';
    cout << bc(12, 7) << '\n';
    cout << bc(20, 10) << '\n';
    return 0;
}
