#include <algorithm>
#include <iostream>
using namespace std;

int adigits(int a, int b, int c)
{
    int x, y, z;
    x = max(a, max(b, c));
    z = min(a, min(b, c));
    y = (a + b + c) - (x + z);
    return x * 100 + y * 10 + z * 1;
}

int main()
{
    cout << adigits(4, 2, 5) << '\n';
    cout << adigits(9, 1, 9) << '\n';
    cout << adigits(1, 2, 3) << '\n';
    cout << adigits(1, 0, 0) << '\n';
    return 0;
}
