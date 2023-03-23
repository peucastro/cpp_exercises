#include "print_string.h"

void split(const string &s, vector<string> &v)
{
    long unsigned int pos_1 = 0;
    long unsigned int pos_2 = 0;

    while (pos_1 < s.size())
    {
        if (s[pos_1] != ' ')
        {
            pos_2 = pos_1;
            string aux;

            while (s[pos_2] != ' ' && pos_2 < s.size())
            {
                aux.push_back(s[pos_2]);
                pos_2++;
            }
            v.push_back(aux);
            pos_1 = pos_2;
        }

        else
            pos_1++;
    }
}

int main()
{
    string s = "C++ LEIC FCUP FEUP";
    vector<string> v;
    split(s, v);
    print(v);
    return 0;
}
