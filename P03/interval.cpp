#include "interval.h"

bool aux(time_of_day a, time_of_day b)
{
    return (a.h < b.h) || (a.h == b.h && a.m < b.m) ? true : false;
}

interval intersection(interval a, interval b)
{
    interval il;

    unsigned int a_start = (a.start.h * 60 + a.start.m);
    unsigned int b_start = (b.start.h * 60 + b.start.m);
    unsigned int a_end = (a.end.h * 60 + a.end.m);
    unsigned int b_end = (b.end.h * 60 + b.end.m);

    if (a_end <= b_start || b_end <= a_start)
        return {{0, 0}, {0, 0}};
    else
    {
        if (b_start >= a_start)
            il.start = b.start;
        else if (a_start >= b_start)
            il.start = a.start;

        if (b_end >= a_end)
            il.end = a.end;
        else if (a_end >= b_end)
            il.end = b.end;
    }
    return il;
}

int main()
{
    cout << intersection({{12, 30}, {14, 30}}, {{17, 30}, {18, 30}}) << '\n';
    cout << intersection({{12, 30}, {14, 30}}, {{14, 30}, {18, 30}}) << '\n';
    cout << intersection({{12, 30}, {14, 31}}, {{14, 30}, {18, 30}}) << '\n';
    cout << intersection({{14, 30}, {15, 59}}, {{11, 30}, {14, 31}}) << '\n';
    cout << intersection({{4, 30}, {7, 59}}, {{4, 0}, {7, 29}}) << '\n';
    cout << intersection({{23, 0}, {23, 58}}, {{22, 45}, {23, 59}}) << '\n';
    return 0;
}
