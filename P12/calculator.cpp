#include "Operation.h"
#include <iostream>
#include <cmath>
using namespace std;

class Sum : public Operation
{
public:
    Sum(int op1, int op2) : Operation(op1, op2) { ans_sum = get_op1() + get_op2(); }

    int operation() const { return ans_sum; }

private:
    int ans_sum;
};

class Power : public Operation
{
public:
    Power(int op1, int op2) : Operation(op1, op2) { ans_pow = pow(op1, op2); }

    int operation() const { return ans_pow; }

private:
    int ans_pow;
};

int main()
{
    {
        const Operation &s = Sum(2, 10);
        cout << s.operation() << ' ';
        const Operation &p = Power(2, 10);
        cout << p.operation() << endl;
    }
    {
        Sum s(6, -2);
        cout << s.operation() << ' ';
        Power p(-3, 0);
        cout << p.operation() << endl;
    }
    {
        Sum s(-6, 2);
        cout << s.operation() << ' ';
        Power p(-2, 5);
        cout << p.operation() << endl;
    }
    {
        Sum s(-6, -2);
        cout << s.operation() << ' ';
        Power p(2, 7);
        cout << p.operation() << endl;
    }
    return 0;
}
