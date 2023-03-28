#include "print_array.h"

void merge_arrays(const int a[], int na, const int b[], int nb, int c[])
{
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
}

int main()
{
    {
        const int NA = 4, NB = 6;
        int a[NA] = {1, 2, 4, 7};
        int b[NB] = {0, 3, 5, 6, 8, 9};
        int c[NA + NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA + NB);
    }
    {
        const int NA = 6, NB = 4;
        int a[NA] = {0, 3, 5, 6, 8, 9};
        int b[NB] = {1, 2, 4, 7};
        int c[NA + NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA + NB);
    }
    {
        const int NA = 2, NB = 3;
        int a[NA] = {0, 1};
        int b[NB] = {2, 3, 4};
        int c[NA + NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA + NB);
    }
    {
        const int NA = 3, NB = 2;
        int a[NA] = {2, 3, 4};
        int b[NB] = {0, 1};
        int c[NA + NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA + NB);
    }
    {
        const int NA = 15, NB = 15;
        int a[NA] = {0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9};
        int b[NB] = {0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9};
        int c[NA + NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA + NB);
    }
    return 0;
}
