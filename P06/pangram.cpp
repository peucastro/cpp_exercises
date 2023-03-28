#include <iostream>
using namespace std;

bool pangram(const string &s, string &m)
{
    int size = s.length();
    int alphabet[26] = {0};

    for (int i = 0; i < size; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            alphabet[s[i] - 'a']++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            alphabet[s[i] - 'A']++;
    }

    bool pan_flag = true;

    for (int j = 0; j < 26; j++)
    {
        if (alphabet[j] == 0)
        {
            m.push_back('a' + j);
            pan_flag = false;
        }
    }
    return pan_flag;
}

int main()
{
    {
        string s = "";
        string m = "";
        bool r = pangram(s, m);
        cout << '\"' << s << "\" "
             << boolalpha << r << " \"" << m << "\"\n";
    }
    {
        string s = "The quick brown fox jumps over the lazy dog";
        string m = "";
        bool r = pangram(s, m);
        cout << '\"' << s << "\" "
             << boolalpha << r << " \"" << m << "\"\n";
    }
    {
        string s = "A quick brown fox jumps over a classy dog";
        string m = "";
        bool r = pangram(s, m);
        cout << '\"' << s << "\" "
             << boolalpha << r << " \"" << m << "\"\n";
    }
    {
        string s = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
        string m = "";
        bool r = pangram(s, m);
        cout << '\"' << s << "\" "
             << boolalpha << r << " \"" << m << "\"\n";
    }
    {
        string s = " Stu yZ abC GhI MnO pQr   ";
        string m = "";
        bool r = pangram(s, m);
        cout << '\"' << s << "\" "
             << boolalpha << r << " \"" << m << "\"\n";
    }
    return 0;
}
