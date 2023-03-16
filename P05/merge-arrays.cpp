#include "print_array.h"

int *merge_arrays(const int a[], int na, const int b[], int nb)
{
    int *c = new int[na + nb];

    for (int i = 0; i < na; i++)
    {
        c[i] = a[i];
    }
    for (int i = na; i < na + nb; i++)
    {
        c[i] = b[i - na];
    }

    for (int i = 0; i < na + nb; i++)
    {
        for (int j = i + 1; j < na + nb; j++)
        {
            if (c[i] > c[j])
            {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    return c;
}

int main()
{
    const int NA = 15, NB = 15;
    int a[NA] = {0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9};
    int b[NB] = {0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9};
    int *c = merge_arrays(a, NA, b, NB);
    print_array(c, NA + NB);
    delete[] c;
    return 0;
}
