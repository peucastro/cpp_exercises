class Fraction
{
public:
    Fraction();
    Fraction(int numerator, int denominator);
    int numerator() const;
    int denominator() const;
    int gcd(int a, int b);
    int lcm(int a, int b);
    void normalise();
    void write() const;
    Fraction sum(const Fraction &right);
    Fraction sub(const Fraction &right);
    Fraction mul(const Fraction &right);
    Fraction div(const Fraction &right);
private:
    int numerator_;
    int denominator_;
};

#include "fraction_aux.h"

Fraction::Fraction()
{
    numerator_ = 0;
    denominator_ = 1;
    normalise();
}

Fraction::Fraction(int numerator, int denominator)
{
    numerator_ = numerator;
    denominator_ = denominator;
    normalise();
}

int Fraction::numerator() const
{
    return numerator_;
}

int Fraction::denominator() const
{
    return denominator_;
}

int Fraction::lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

Fraction Fraction::sum(const Fraction &right)
{
    Fraction ans(lcm(denominator_, right.denominator()) / denominator_ * numerator_ + lcm(denominator_, right.denominator()) / right.denominator() * right.numerator(), lcm(denominator_, right.denominator()));
    ans.normalise();
    return ans;
}

Fraction Fraction::sub(const Fraction &right)
{
    Fraction ans(lcm(denominator_, right.denominator()) / denominator_ * numerator_ - lcm(denominator_, right.denominator()) / right.denominator() * right.numerator(), lcm(denominator_, right.denominator()));
    ans.normalise();
    return ans;
}

Fraction Fraction::mul(const Fraction &right)
{
    Fraction ans(numerator_ * right.numerator(), denominator_ * right.denominator());
    ans.normalise();
    return ans;
}

Fraction Fraction::div(const Fraction &right)
{
    Fraction aux(right.denominator(), right.numerator());
    Fraction ans(numerator_ * aux.numerator(), denominator_ * aux.denominator());
    ans.normalise();
    return ans;
}

int main()
{
    cout << "SUM:" << endl;
    {
        Fraction().sum({2, 4}).write();
        cout << ' ';
        Fraction(1, 1).sum({2, 4}).write();
        cout << ' ';
        Fraction(2, 4).sum({3, 9}).write();
        cout << ' ';
        Fraction(-2, 4).sum({1, 2}).write();
        cout << ' ';
        Fraction(3, 27).sum({-27, 81}).write();
        cout << '\n' << endl;
    }
    cout << "SUBTRACTION:" << endl;
    {
        Fraction().sub({2, 4}).write();
        cout << ' ';
        Fraction(1, 1).sub({2, 4}).write();
        cout << ' ';
        Fraction(2, 4).sub({3, 9}).write();
        cout << ' ';
        Fraction(-2, 4).sub({1, 2}).write();
        cout << ' ';
        Fraction(3, 27).sub({-27, 81}).write();
        cout << '\n' << endl;
    }
    cout << "MULTIPLICATION:" << endl;
    {
        Fraction().mul({2, 4}).write();
        cout << ' ';
        Fraction(1, 1).mul({2, 4}).write();
        cout << ' ';
        Fraction(2, 4).mul({3, 9}).write();
        cout << ' ';
        Fraction(-2, 4).mul({1, 2}).write();
        cout << ' ';
        Fraction(3, 27).mul({-27, 81}).write();
        cout << '\n' << endl;
    }
    cout << "DIVISION:" << endl;
    {
        Fraction().div({2, 4}).write();
        cout << ' ';
        Fraction(1, 1).div({2, 4}).write();
        cout << ' ';
        Fraction(2, 4).div({3, 9}).write();
        cout << ' ';
        Fraction(-2, 4).div({1, 2}).write();
        cout << ' ';
        Fraction(3, 27).div({-27, 81}).write();
        cout << '\n' << endl;
    }
    return 0;
}
