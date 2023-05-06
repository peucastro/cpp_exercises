#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int k, d;
    cin >> k >> d;
    double x;

    for (int i = 0; i <= k; i++)
        x += 4 * ((pow(-1, i)) / (2 * i + 1));
    cout << fixed << setprecision(d) << x;
    return 0;
}
