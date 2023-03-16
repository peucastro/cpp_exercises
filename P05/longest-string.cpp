#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
        size++;
    return size;
}

const char *longest(const char *pa[])
{

    int i = 0, k = 0;
    while (pa[i] != nullptr)
    {
        if (array_size(pa[i]) >= array_size(pa[k]))
            k = i;
        i++;
    }

    return pa[k];
}

int main()
{
    const char *pa[] = {"C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr};
    cout << "\"" << longest(pa) << "\"\n";
    return 0;
}
