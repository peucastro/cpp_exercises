#include "Date2.h"
#include <sstream>
using namespace std;

bool isLeap(int y)
{
    if (y % 4 != 0 || y % 100 == 0)
        if (y % 400 != 0)
            return false;
    return true;
}

bool validate(int y, int m, int d)
{
    int days_in_month;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days_in_month = 31;
        break;

    case 2:
        if (isLeap(y))
        {
            days_in_month = 29;
            break;
        }
        days_in_month = 28;
        break;

    default:
        days_in_month = 30;
        break;
    }

    if (y == 0 || m == 0 || y == 0)
        return false;
    else if (m < 1 || m > 12)
        return false;
    else if (d > days_in_month)
        return false;
    return true;
}

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 1;
}

Date::Date(int year, int month, int day)
{
    if (validate(year, month, day))
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else
    {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }
}

Date::Date(const std::string &year_month_day)
{
    istringstream string(year_month_day);
    int year;
    int month;
    int day;
    char c;
    bool flag = true;

    string >> year;
    string >> c;
    if (c != '/')
        flag = false;
    string >> month;
    string >> c;
    if (c != '/')
        flag = false;
    string >> day;

    if (validate(year, month, day) && flag)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else
    {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }
}

bool Date::is_valid() const
{
    if (this->day == 0 || this->month == 0 || this->year == 0)
        return false;
    return true;
}

int main()
{
    Date d1;
    d1.write();
    cout << (d1.is_valid() ? "" : "-invalid") << endl;
    Date d2(2022, 4, 31);
    d2.write();
    cout << (d2.is_valid() ? "" : "-invalid") << endl;
    Date d3("2ooo/2/28");
    d3.write();
    cout << (d3.is_valid() ? "" : "-invalid") << endl;
    Date d4("1900/1/1");
    d4.write();
    cout << (d4.is_valid() ? "" : "-invalid") << endl;
    Date d5("2022#12#31");
    d5.write();
    cout << (d5.is_valid() ? "" : "-invalid") << endl;
    return 0;
}
