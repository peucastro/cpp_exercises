#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

template <typename Itr>
string to_string(Itr start, Itr end)
{
    ostringstream str;
    str << "[ ";
    for (Itr p = start; p != end; p++)
    {
        str << *p << ' ';
    }
    str << ']';
    return str.str();
}

template <typename Itr, typename T>
int replace(Itr start, Itr end, const T &a, const T &b)
{
    int count = 0;
    for (Itr p = start; p != end; p++)
    {
        if (*p == a)
        {
            *p = b;
            count++;
        }
    }
    return count;
}

int main()
{
    {
        vector<int> v;
        cout << replace(v.begin(), v.end(), 0, 1) << ' '
             << to_string(v.cbegin(), v.cend()) << '\n';
    }
    {
        vector<int> v{1, 2, 3, 3, 4};
        cout << replace(v.begin(), v.end(), 3, 0) << ' '
             << to_string(v.cbegin(), v.cend()) << '\n';
    }
    {
        vector<int> v{5, 1, 2, 3, 4, 5};
        cout << replace(v.begin() + 1, v.end() - 1, 5, 0) << ' '
             << to_string(v.cbegin(), v.cend()) << '\n';
    }
    {
        list<string> l{"C++", "Java", "C++", "Python", "Rust", "C"};
        cout << replace(l.begin(), l.end(), string("C++"), string("Rust")) << ' '
             << replace(l.begin(), l.end(), string("C"), string("Rust")) << ' '
             << to_string(l.cbegin(), l.cend()) << '\n';
    }
    {
        string s = "Hello world";
        cout << replace(s.begin(), s.end(), 'l', 'L') << ' '
             << to_string(s.cbegin(), s.cend()) << ' '
             << replace(s.rbegin(), s.rend(), 'o', 'O') << ' '
             << to_string(s.crbegin(), s.crend()) << ' '
             << to_string(s.cbegin(), s.cend()) << '\n';
    }
    return 0;
}
