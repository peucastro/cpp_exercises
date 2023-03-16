#include "fraction.h"

int gcd(int num1, int num2)
{
    if (num2 == 0)
        return abs(num1);
    else
        return abs(gcd(num2, num1 % num2));
}

int lcm(int num1, int num2) { return (num1 / gcd(num1, num2)) * num2; }

fraction sum(const fraction fa[], int n)
{
    fraction ans = {0, 0};

    if (n == 1)
    {
        ans.den = fa[0].den;
        ans.num = fa[0].num;
    }
    else if (n == 2)
    {
        ans.den = lcm(fa[0].den, fa[1].den);
        ans.num = (ans.den / fa[0].den * fa[0].num) + (ans.den / fa[1].den * fa[1].num);
    }
    else
    {
        ans.den = lcm(fa[0].den, fa[1].den);
        for (int i = 2; i < n; i++)
        {
            ans.den = lcm(ans.den, fa[i].den);
        }

        for (int j = 0; j < n; j++)
        {
            ans.num += ans.den / fa[j].den * fa[j].num;
        }
    }

    int div = gcd(ans.num, ans.den);
    ans.den /= div;
    ans.num /= div;

    return {ans.num, ans.den};
}

int main()
{
    const int n = 5;
    const fraction fa[n]{{0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5}};
    cout << sum(fa, n) << '\n';
    return 0;
}
