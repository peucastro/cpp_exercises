#include "print_array.h"

int filter_duplicates(const int a[], int n, int b[])
{
    b[0] = a[0];
    int nf = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            b[nf] = a[i];
            nf++;
        }
    }
    return nf;
}

int main()
{
    const int n = 11;
    const int a[n] = {1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 33};
    int b[n] = {0};
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf);
    return 0;
}
