#include <iostream>
#include <algorithm>
using namespace std;

int median(const int a[], int n)
{
    int *tmp = new int[n];
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        tmp[i] = a[i];
    }

    sort(tmp, tmp + n);

    if (n % 2 == 0)
        ans = (tmp[n / 2 - 1] + tmp[n / 2]) / 2;
    else
        ans = tmp[n / 2];

    delete[] tmp;
    return ans;
}

int main()

{
    const int n = 6;
    int a[n]{30, 10, 0, -20, 14, 20};
    cout << median(a, n) << '\n';
    return 0;
}
