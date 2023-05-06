#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void show_vector(const vector<pair<string, size_t>> &count)
{
    cout << "[ ";
    for (const auto &e : count)
    {
        cout << e.first << ":" << e.second << ' ';
    }
    cout << "]\n";
}

void to_lower(string &str)
{
    for (char &p : str)
        p = tolower(p);
}

void count_words(const string &str, vector<pair<string, size_t>> &count)
{
    istringstream phrase(str);
    string word;

    while (phrase >> word)
    {
        to_lower(word);
        bool find = false;

        for (pair<string, size_t> &p : count)
        {
            if (p.first == word)
            {
                p.second++;
                find = true;
            }
        }
        if (!find)
            count.push_back(pair<string, size_t>(word, 1));
    }
    sort(count.begin(), count.end());
}

int main()
{
    {
        string s = "If you want to buy  buy  if you don't want to buy  bye bye";
        vector<pair<string, size_t>> count;
        count_words(s, count);
        show_vector(count);
    }
    {
        string s = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
        vector<pair<string, size_t>> count;
        count_words(s, count);
        show_vector(count);
    }
    {
        string s = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
        vector<pair<string, size_t>> count;
        count_words(s, count);
        show_vector(count);
    }
    {
        string s = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
        vector<pair<string, size_t>> count;
        count_words(s, count);
        show_vector(count);
    }
    {
        string s = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";
        vector<pair<string, size_t>> count;
        count_words(s, count);
        show_vector(count);
    }
    return 0;
}
