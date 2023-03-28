#include "print.h"

string to_upper(const string str)
{
    string upper = str;
    for (char &c : upper)
        c = toupper(c);
    return upper;
}

void normalise(const string &input_fname, const string &output_fname)
{
    ifstream in(input_fname);
    ofstream out(output_fname);

    string line;
    string word;
    while (getline(in, line))
    {

        line.erase(0, line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ') + 1);
        if (line == "")
            continue;

        out << to_upper(line);
        out << endl;
    }
}

int main()
{
    {
        normalise("p3_test1.txt", "p3_test1_out.txt");
        print("p3_test1_out.txt");
    }
    cout << endl;
    {
        normalise("p3_test2.txt", "p3_test2_out.txt");
        print("p3_test2_out.txt");
    }
    cout << endl;

    {
        normalise("p3_test3.txt", "p3_test3_out.txt");
        print("p3_test3_out.txt");
    }
    cout << endl;

    {
        normalise("p3_test4.txt", "p3_test4_out.txt");
        print("p3_test4_out.txt");
    }
    cout << endl;

    {
        normalise("p3_test5.txt", "p3_test5_out.txt");
        print("p3_test5_out.txt");
    }
    return 0;
}
