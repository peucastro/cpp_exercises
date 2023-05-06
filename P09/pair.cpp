#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T1, typename T2>
class Pair
{
public:
    Pair(T1 first, T2 second);
    T1 get_first() const;
    T2 get_second() const;
    void show() const;
private:
    T1 first;
    T2 second;
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 first, T2 second)
{
    this->first = first;
    this->second = second;
}

template <typename T1, typename T2>
T1 Pair<T1, T2>::get_first() const
{
    return this->first;
}

template <typename T1, typename T2>
T2 Pair<T1, T2>::get_second() const
{
    return this->second;
}

template <typename T1, typename T2>
void Pair<T1, T2>::show() const
{
    cout << '{' << this->first << ',' << this->second << '}';
}

bool compare_func_first(Pair<string, int> pair_1, Pair<string, int> pair_2)
{
    if (pair_1.get_first() < pair_2.get_first())
        return true;
    return false;
}

void sort_by_first(vector<Pair<string, int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), compare_func_first);
}

bool compare_func_second(Pair<string, int> pair_1, Pair<string, int> pair_2)
{
    if (pair_1.get_second() < pair_2.get_second())
        return true;
    return false;
}

void sort_by_second(vector<Pair<string, int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), compare_func_second);
}

void show(vector<Pair<string, int>> pairs)
{
    cout << '{';
    for (Pair<string, int> p : pairs)
        p.show();
    cout << '}';
}

int main()
{
    {
        vector<Pair<string, int>> persons = {{"Maria", 17}, {"Ana", 21}, {"Pedro", 19}};
        sort_by_first(persons);
        show(persons);
        cout << '\n';
    }
    {
        vector<Pair<string, int>> persons = {{"Ana", 19}, {"Rui", 16}};
        sort_by_second(persons);
        show(persons);
        cout << '\n';
    }
    {
        vector<Pair<string, int>> teams = {{"Porto", 91}, {"Benfica", 74}, {"Sporting", 85}};
        sort_by_first(teams);
        show(teams);
        cout << '\n';
    }
    {
        vector<Pair<string, int>> teams = {{"Porto", 91}, {"Benfica", 74}, {"Sporting", 85}};
        sort_by_second(teams);
        show(teams);
        cout << '\n';
    }
    {
        vector<Pair<string, int>> calories = {{"orange", 37}, {"egg", 146}, {"apple", 56}, {"yogurt", 51}};
        sort_by_second(calories);
        show(calories);
        cout << '\n';
    }
    return 0;
}
