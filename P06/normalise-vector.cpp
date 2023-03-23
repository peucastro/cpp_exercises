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
    vector<string> v{"Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier"};
    normalise(v, string("Antonio"), string("Zacarias"));
    print(v);
    return 0;
}
