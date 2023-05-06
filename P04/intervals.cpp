#include "interval.h"

int time_to_int(time_of_day t)
{
    return t.h * 60 + t.m;
}

int search_intervals(time_of_day t, const interval a[], int n, interval &u)
{
    bool first_flag = true;
    for (int i = 0; i < n; i++)
    {
        if (time_to_int(t) >= time_to_int(a[i].start) && time_to_int(t) < time_to_int(a[i].end))
        {
            if (first_flag)
            {
                u.start = a[i].start;
                u.end = a[i].end;
                first_flag = false;
            }
            if (time_to_int(a[i].start) < time_to_int(u.start))
                u.start = a[i].start;
            if (time_to_int(a[i].end) > time_to_int(u.end))
                u.end = a[i].end;
        }
    }

    int u_range = time_to_int(u.end) - time_to_int(u.start);
    if (first_flag)
    {
        u = {t, t};
        return 0;
    }
    return u_range;
}

int main()
{
    {
        const int n = 1;
        const time_of_day t = {13, 00};
        const interval a[n]{{{12, 30}, {14, 30}}};
        interval u;
        int d = search_intervals(t, a, n, u);
        cout << d << ' ' << u << '\n';
    }
    {
        const int n = 2;
        const time_of_day t = {14, 30};
        const interval a[n]{{{12, 30}, {14, 30}},
                            {{14, 30}, {15, 30}}};
        interval u;
        int d = search_intervals(t, a, n, u);
        cout << d << ' ' << u << '\n';
    }
    {
        const int n = 2;
        const time_of_day t = {12, 30};
        const interval a[n]{{{12, 30}, {14, 30}},
                            {{14, 30}, {15, 30}}};
        interval u;
        int d = search_intervals(t, a, n, u);
        cout << d << ' ' << u << '\n';
    }
    {
        const int n = 2;
        const time_of_day t = {15, 30};
        const interval a[n]{{{12, 30}, {14, 30}},
                            {{14, 30}, {15, 30}}};
        interval u;
        int d = search_intervals(t, a, n, u);
        cout << d << ' ' << u << '\n';
    }
    {
        const int n = 5;
        const time_of_day t = {15, 15};
        const interval a[n]{{{12, 30}, {14, 30}},
                            {{14, 30}, {15, 30}},
                            {{15, 10}, {16, 10}},
                            {{9, 30}, {15, 15}},
                            {{9, 45}, {15, 16}}};
        interval u;
        int d = search_intervals(t, a, n, u);
        cout << d << ' ' << u << '\n';
    }
    return 0;
}
