#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
    {
        size++;
    }
    return size;
}

int nrl(const char s[], char low[])
{
    int alphabet[26] = {0};
    int size = array_size(s);

    for (int i = 0; i < size; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            alphabet[s[i] - 'a']++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            alphabet[s[i] - 'A']++;
    }

    int low_count = 0;
    for (int j = 0; j < 26; j++)
    {
        if (alphabet[j] == 1)
        {
            low[low_count] = j + 'a';
            low_count++;
        }
    }
    low[low_count] = '\0';
    return low_count;
}

int main()
{
    const char s[] = "The quick brown fox jumps over the lazy dog";
    char l[27] = {-1};
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
}
