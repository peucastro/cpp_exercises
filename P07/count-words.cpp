#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
string to_lower(T str)
{
    string lower;
    for (char &c : str)
        lower.push_back(tolower(c));
    return lower;
}

int count(const string &fname, const string &word)
{
    ifstream file(fname);

    string input;
    int count = 0;
    while (file >> input)
    {
        if (to_lower(input) == to_lower(word))
        {
            count++;
        }
    }
    file.close();
    return count;
}

int main()
{
    cout << count("p1_test_a.txt", "THE") << '\n';
    cout << count("p1_test_a.txt", "0") << '\n';
    cout << count("p1_test_a.txt", "code") << '\n';
    cout << count("p1_test_b.txt", "Collider") << '\n';
    cout << count("p1_test_b.txt", "you") << '\n';
    return 0;
}
