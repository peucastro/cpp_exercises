#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

double average(const string &fname)
{
    ifstream in(fname);

    double num, sum, count;
    sum = count = 0;

    while (true)
    {
        if (in.eof())
            break;
        else if (in >> num)
        {
            sum += num;
            count++;
        }
        in.clear();
        in.ignore(1);
    }
    return sum / count;
}

int main()
{
    {
        double m = average("p6_test1.txt");
        cout << fixed << setprecision(2) << m << '\n';
    }
    {
        double m = average("p6_test2.txt");
        cout << fixed << setprecision(2) << m << '\n';
    }
    {
        double m = average("p6_test3.txt");
        cout << fixed << setprecision(2) << m << '\n';
    }
    {
        double m = average("p6_test4.txt");
        cout << fixed << setprecision(2) << m << '\n';
    }
    {
        double m = average("p6_test5.txt");
        cout << fixed << setprecision(2) << m << '\n';
    }
    return 0;
}
