#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

unsigned roman_to_arab(const string &roman)
{
    unsigned ans = 0;
    for (size_t i = 0; i < roman.length(); i++)
    {
        unsigned curr;
        unsigned next;
        for (pair<char, unsigned> p : roman_to_int)
        {
            if (p.first == roman[i])
                curr = p.second;
            if (p.first == roman[i + 1])
                next = p.second;
        }
        ans += curr < next ? (-1) * curr : curr;
    }
    return ans;
}

int main()
{
    {
        string r = "XV";
        cout << roman_to_arab(r) << '\n';
    }
    {
        string r = "LXXXIV";
        cout << roman_to_arab(r) << '\n';
    }
    {
        string r = "CMLXIV";
        cout << roman_to_arab(r) << '\n';
    }
    {
        string r = "MMMCMXCIX";
        cout << roman_to_arab(r) << '\n';
    }
    {
        string r = "MMMDCCCLXXXVIII";
        cout << roman_to_arab(r) << '\n';
    }
    return 0;
}
