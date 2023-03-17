#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
        size++;
    return size;
}

char *repeat(const char str[], int n)
{
    int size = array_size(str) * n + 1;
    char* ans = new char[size];

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[j] == '\0')
            j = 0;
        ans[i] = str[j];
        j++;
    }
    ans[size - 1] = '\0';
    return ans;
}

int main()
{
    const char str[] = "C/C++@LEIC.";
    char *r = repeat(str, 5);
    cout << "\"" << r << "\"\n";
    delete[] r;
    return 0;
}
