#include "complex.h"

complex sum(complex a, complex b)
{
    return {a.real + b.real, a.img + b.img};
}

complex mul(complex a, complex b)
{
    return {a.real * b.real - a.img * b.img, a.real * b.img + a.img * b.real};
}

void mandel(complex c, int n, complex z[])
{
    complex z_0 = {0, 0};

    z[0] = {0, 0};
    int j = 1;

    for (int i = 1; i < n; i++)
    {
        complex mult = mul(z_0, z_0);
        complex z_n = sum(mult, c);
        z[j] = z_n;
        z_0 = z_n;
        j++;
    }
}

int main()
{
    complex c = {0, 3};
    const int n = 5;
    complex z[n];
    mandel(c, n, z);
    print(z, n);
    return 0;
}
