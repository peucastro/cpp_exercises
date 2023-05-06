#include "show_file.h"

void calc_medians(const string &input_fname, const string &output_fname)
{
    ifstream in(input_fname);
    ofstream out(output_fname);

    string line;
    double number;
    string str;
    vector<double> values;

    while (getline(in, line))
    {
        if (line[0] == '#')
            continue;

        istringstream iss(line);
        iss >> str;
        out << str << ' ';

        while (iss >> number)
            values.push_back(number);

        sort(values.begin(), values.end());

        if (values.size() % 2 != 0)
            out << fixed << setprecision(1) << values[values.size() / 2] << endl;
        else
            out << fixed << setprecision(1) << 0.5 * (values[values.size() / 2 - 1] + values[values.size() / 2]) << endl;

        values.clear();
    }
}

int main()
{
    {
        calc_medians("p5_test1.txt", "p5_test1_out.txt");
        show_file("p5_test1_out.txt");
    }
    cout << endl;
    {
        calc_medians("p5_test2.txt", "p5_test2_out.txt");
        show_file("p5_test2_out.txt");
    }
    cout << endl;
    {
        calc_medians("p5_test3.txt", "p5_test3_out.txt");
        show_file("p5_test3_out.txt");
    }
    cout << endl;
    {
        calc_medians("p5_test4.txt", "p5_test4_out.txt");
        show_file("p5_test4_out.txt");
    }
    cout << endl;
    {
        calc_medians("p5_test5.txt", "p5_test5_out.txt");
        show_file("p5_test5_out.txt");
    }
    return 0;
}
