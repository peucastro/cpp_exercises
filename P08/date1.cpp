#include "Date1.h"
using namespace std;

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 1;
}

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::get_year() const
{
    return this->year;
}

int Date::get_month() const
{
    return this->month;
}

int Date::get_day() const
{
    return this->day;
}

bool is_before(const Date &date1, const Date &date2)
{
    if ((date1.get_year() < date2.get_year()) || (date1.get_year() == date2.get_year() && date1.get_month() < date2.get_month()) || (date1.get_year() == date2.get_year() && date1.get_month() == date2.get_month() && date1.get_day() < date2.get_day()))
        return true;
    return false;
}

int main()
{
    Date d1;
    d1.write();
    cout << '\n';
    Date d2(2020, 2, 29);
    d2.write();
    cout << '\n';
    Date d3(1925, 4, 30);
    d3.write();
    cout << '\n';
    Date d4, d5(2022, 4, 29);
    d4.write();
    cout << '-' << boolalpha << is_before(d4, d5) << '\n';
    Date d6(2023, 10, 31), d7(2022, 4, 29);
    d6.write();
    cout << '-' << boolalpha << is_before(d6, d7) << '\n';
    return 0;
}
