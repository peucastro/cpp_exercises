#include <iostream>
using namespace std;

int max(const int a[], int n)
{
    int ans = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans)
            ans = a[i];
    }
    return ans;
}

int main()
{
    const int n = 9;
    const int a[n] = {10, 20, 30, -2, 50, 3, 1, 50, 49};
    cout << max(a, n) << '\n';
    return 0;
}
