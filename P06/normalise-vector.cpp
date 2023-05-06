#include "print_vector.h"

template <typename T>
void normalise(vector<T> &v, const T &min, const T &max)
{
    for (long unsigned int i = 0; i < v.size(); i++)
    {
        if (v[i] < min)
            v[i] = min;
        else if (v[i] > max)
            v[i] = max;
    }
}

int main()
{
    {
        vector<int> v{};
        normalise(v, 0, 1);
        print(v);
    }
    {
        vector<int> v{1, 2, 3, 4, 5};
        normalise(v, 1, 5);
        print(v);
    }
    {
        vector<int> v{1, 2, 3, 4, 5};
        normalise(v, 3, 4);
        print(v);
    }
    {
        vector<double> v{-1.2, 2.2, -3.5, 4.3, 5.2};
        normalise(v, 0.5, 5.1);
        print(v);
    }
    {
        vector<string> v{"Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier"};
        normalise(v, string("Antonio"), string("Zacarias"));
        print(v);
    }
    return 0;
}
