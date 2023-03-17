#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
        size++;
    return size;
}

bool pangram(const char s[], char m[])
{
    int size = array_size(s);
    int alphabet[26] = {0};

    for (int i = 0; i < size; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            alphabet[s[i] - 'a']++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            alphabet[s[i] - 'A']++;
    }

    int mc = 0;
    bool pan_flag = true;

    for (int j = 0; j < 26; j++)
    {
        if (alphabet[j] == 0)
        {
            m[mc] = 'a' + j;
            mc++;
            pan_flag = false;
        }
    }
    m[mc] = '\0';
    return pan_flag;
}

int main()
{
    char s[] = " Stu yZ abC GhI MnO pQr   ";
    char m[27] = {-1};
    bool r = pangram(s, m);
    cout << '\"' << s << "\" "
         << boolalpha << r << " \"" << m << "\"\n";
    return 0;
}
