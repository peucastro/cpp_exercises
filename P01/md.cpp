#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, x1, y1, x2, y2, res = 0;
    cin >> n;
    cin >> x1 >> y1;

    for (int i = 1; i < n; i++)
    {
        cin >> x2 >> y2;
        res += abs(x1 - x2) + abs(y1 - y2);

        x1 = x2;
        y1 = y2;
    }
    cout << res;
    return 0;
}
