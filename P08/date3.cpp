#include "Date3.h"
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
    this->yyyymmdd = "00010101";
}

Date::Date(int year, int month, int day)
{
    if (validate(year, month, day))
        this->yyyymmdd = to_string(year).append(to_string(month)).append(to_string(day));
    else
        this->yyyymmdd = "00000000";
}

Date::Date(const std::string &year_month_day)
{
    istringstream text(year_month_day);
    int year;
    int month;
    int day;
    char c;
    bool flag = true;

    text >> year;
    text >> c;
    if (c != '/')
        flag = false;
    text >> month;
    text >> c;
    if (c != '/')
        flag = false;
    text >> day;

    if (validate(year, month, day) && flag)
    {
        string year_str = to_string(year);
        string month_str = to_string(month);
        string day_str = to_string(day);

        string aux = "0";
        while (year_str.size() < 4)
            year_str = aux.append(year_str);
        while (month_str.size() < 2)
            month_str = aux.append(month_str);
        while (day_str.size() < 2)
            day_str = aux.append(day_str);

        yyyymmdd = year_str.append(month_str).append(day_str);
    }
    else
        this->yyyymmdd = "00000000";
}

int Date::get_year() const
{
    return stoi(yyyymmdd.substr(0, 4));
}

int Date::get_month() const
{
    return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_day() const
{
    return stoi(yyyymmdd.substr(6, 2));
}

bool Date::is_valid() const
{
    if (get_day() == 0 || get_month() == 0 || get_year() == 0)
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
