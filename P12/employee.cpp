#include <iostream>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
using namespace std;

void SalariedEmployee::calculate_net_pay()
{
    set_net_pay(salary_);
}

void HourlyEmployee::calculate_net_pay()
{
    set_net_pay(wage_rate_ * hours_);
}

void read_hours_worked(vector<Employee *> &employees)
{
    for (size_t i = 0; i < employees.size(); i++)
    {
        HourlyEmployee *t = dynamic_cast<HourlyEmployee *>(employees.at(i));
        if (t != nullptr)
        {
            double inp;
            cin >> inp;
            t->set_hours(inp);
        }
    }
}

void calculate_pay(vector<Employee *> &employees)
{
    for (Employee *e : employees)
        e->calculate_net_pay();
}

void print_checks(const vector<Employee *> &employees)
{
    cout << "| ";
    for (Employee *e : employees)
    {
        e->print_check();
        cout << " | ";
    }
}

int main()
{
    {
        vector<Employee *> employees = {
            new SalariedEmployee("John", 2000),
            new HourlyEmployee("Mary", 10)};
        read_hours_worked(employees);
        calculate_pay(employees);
        print_checks(employees);
        for (const auto &e : employees)
            delete e;
    }
    {
        vector<Employee *> employees = {
            new HourlyEmployee("Peter", 10.31),
            new SalariedEmployee("Ann", 1957.4)};
        read_hours_worked(employees);
        calculate_pay(employees);
        print_checks(employees);
        for (const auto &e : employees)
            delete e;
    }
    {
        vector<Employee *> employees = {
            new HourlyEmployee("Philip", 10.75),
            new HourlyEmployee("Elisabeth", 9.5),
            new SalariedEmployee("Charles", 5000)};
        read_hours_worked(employees);
        calculate_pay(employees);
        print_checks(employees);
        for (const auto &e : employees)
            delete e;
    }
    {
        vector<Employee *> employees = {
            new SalariedEmployee("John", 2123.5),
            new SalariedEmployee("Peter", 1999.9)};
        read_hours_worked(employees);
        calculate_pay(employees);
        print_checks(employees);
        for (const auto &e : employees)
            delete e;
    }
    return 0;
}
