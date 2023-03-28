#include "wc.h"

wcresult wc(const string &filename)
{
    ifstream file(filename);
    wcresult ans = {0, 0, 0};

    string line;
    string input;
    while (getline(file, line))
    {
        ans.lines++;
        ans.bytes += line.size() + 1;

        istringstream word(line);
        while (word >> input)
            ans.words++;
    }

    file.close();
    return ans;
}

int main()
{
    {
        wcresult r = wc("p2_test1.txt");
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    }
    {
        wcresult r = wc("p2_test2.txt");
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    }
    {
        wcresult r = wc("p2_test3.txt");
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    }
    {
        wcresult r = wc("p2_test4.txt");
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    }
    {
        wcresult r = wc("p2_test5.txt");
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    }
    return 0;
}
