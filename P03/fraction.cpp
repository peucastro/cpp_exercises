#include "fraction.h"

int gcd(int num1, int num2)
{
    if (num2 == 0)
        return abs(num1);
    else
        return abs(gcd(num2, num1 % num2));
}

int lcm(int num1, int num2) { return (num1 / gcd(num1, num2)) * num2; }

fraction add(fraction a, fraction b)
{
    fraction ans;
    ans.den = lcm(a.den, b.den);
    ans.num = (ans.den / a.den * a.num) + (ans.den / b.den * b.num);

    int div = gcd(ans.num, ans.den);
    ans.num /= div;
    ans.den /= div;

    return ans;
}

fraction mul(fraction a, fraction b)
{
    fraction ans;
    ans.num = a.num * b.num;
    ans.den = a.den * b.den;

    int div = gcd(ans.num, ans.den);
    ans.num /= div;
    ans.den /= div;

    return ans;
}

int main()
{
    {
        fraction a{0, 1}, b{2, 1};
        cout << add(a, b) << ' ' << mul(a, b) << '\n';
    }
    {
        fraction a{1, 1}, b{-1, 2};
        cout << add(a, b) << ' ' << mul(a, b) << '\n';
    }
    {
        fraction a{-3, 2}, b{3, 2};
        cout << add(a, b) << ' ' << mul(a, b) << '\n';
    }
    {
        fraction a{-3, 2}, b{-2, 3};
        cout << add(a, b) << ' ' << mul(a, b) << '\n';
    }
    {
        fraction a{-7, 24}, b{1, 3};
        cout << add(a, b) << ' ' << mul(a, b) << '\n';
    }
    {
        fraction a{-8, 25}, b{3, 4};
        cout << add(a, b) << ' ' << mul(a, b) << '\n';
    }
    {
        cout << add({7, 4536}, mul({-5, 21}, add({1, 2}, mul({-2, 3}, {1, 9})))) << '\n';
    }
    return 0;
}
