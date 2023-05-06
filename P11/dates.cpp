#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Date.h"
using namespace std;

bool operator<(const Date &left, const Date &right)
{
    if ((left.getYear() < right.getYear()) || (left.getYear() == right.getYear() && left.getMonth() < right.getMonth()) || (left.getYear() == right.getYear() && left.getMonth() == right.getMonth() && left.getDay() < right.getDay()))
        return true;
    return false;
}

ostream &operator<<(ostream &out, const Date &d)
{
    out << setw(4) << setfill('0') << d.getYear() << '/'
        << setw(2) << setfill('0') << d.getMonth() << '/'
        << setw(2) << setfill('0') << d.getDay();
    return out;
}

int main()
{
    {
        vector<Date> dates = {{2023, 11, 15}, {2021, 12, 8}, {2023, 11, 14}};
        sort(dates.begin(), dates.end());
        for (const auto &d : dates)
            cout << d << " ";
        cout << '\n';
    }
    {
        vector<Date> dates = {{2000, 1, 1}, {2000, 2, 1}, {2000, 12, 31}};
        sort(dates.begin(), dates.end());
        for (const auto &d : dates)
            cout << d << " ";
        cout << '\n';
    }
    {
        vector<Date> dates = {{2001, 10, 31}, {2005, 10, 31}, {2010, 10, 31}, {1992, 10, 31}};
        sort(dates.begin(), dates.end());
        for (const auto &d : dates)
            cout << d << " ";
        cout << '\n';
    }
    {
        vector<Date> dates = {{2023, 4, 28}, {999, 1, 1}};
        sort(dates.begin(), dates.end());
        for (const auto &d : dates)
            cout << d << " ";
        cout << '\n';
    }
    {
        vector<Date> dates = {{2075, 2, 2}, {2077, 10, 10}, {2075, 2, 2}};
        sort(dates.begin(), dates.end());
        for (const auto &d : dates)
            cout << d << " ";
        cout << '\n';
    }
    return 0;
}
