#include <iostream>
using namespace std;

int isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        int res = 0;
        if (isPrime(i))
        {
            int aux = i;
            while (aux != 0)
            {
                res += aux % 2;
                aux /= 2;
            }
            if (isPrime(res))
                cout << i << " ";
        }
    }
    return 0;
}
