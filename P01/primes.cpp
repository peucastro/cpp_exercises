#include <iostream>
using namespace std;

bool isPrime(int n)
{
    bool flag = true;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
    return 0;
}
