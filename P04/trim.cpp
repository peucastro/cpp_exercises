#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
        size++;
    return size;
}

void trim(char s[])
{
    int i = 0;
    while (s[i] == ' ')
        i++;
    for (int j = 0; j < i; j++)
    {
        s[j] = s[i];
        if (s[i] != '\0')
            i++;
    }

    if (s[0] != '\0')
    {
    int end = array_size(s);
    while (s[--end] == ' ');

    if (array_size(s) > 0)
        s[end + 1] = '\0';
    }
}

int main()
{
    char s[] = " abc  _  def  _  ghi ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
}
