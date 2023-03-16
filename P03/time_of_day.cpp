#include "time_of_day.h"

time_of_day tick(time_of_day t)
{
    if (t.m == 59)
    {
        if (t.h == 23)
        {
            t.h = 0;
            t.m = 0;
        }
        else
        {
            t.m = 0;
            t.h += 1;
        }
    }
    else
    {
        t.m += 1;
    }
    return {t.h, t.m};
}

int main()
{
    cout << tick({0, 0}) << '\n';
    cout << tick({12, 30}) << '\n';
    cout << tick({12, 59}) << '\n';
    cout << tick({23, 59}) << '\n';
    cout << tick(tick(tick({23, 59}))) << '\n';
    return 0;
}
