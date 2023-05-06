#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
        size++;
    return size;
}

char *duplicate(const char s[])
{
    int size = array_size(s);
    char *ans = new char[size + 1];

    for (int i = 0; i < size; i++)
    {
        ans[i] = s[i];
    }
    ans[size] = '\0';

    return ans;
}

int main()
{
    {
        char *s = duplicate("");
        cout << "\"" << s << "\"\n";
        delete[] s;
    }
    {
        char *s = duplicate("a");
        cout << "\"" << s << "\"\n";
        delete[] s;
    }
    {
        char *s = duplicate("C++");
        cout << "\"" << s << "\"\n";
        delete[] s;
    }
    {
        char *s = duplicate("0123 456 789 @ abc");
        cout << "\"" << s << "\"\n";
        delete[] s;
    }
    return 0;
}
