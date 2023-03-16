#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int y = pow(x, 2) - x + 1;
    cout << x << ' ' << y << '\n';
    return 0;
}
