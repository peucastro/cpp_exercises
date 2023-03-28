#include "show_file.h"

void maximum(const string &input_fname, const string &output_fname)
{
    ifstream in(input_fname);
    ofstream out(output_fname);

    double x;
    int count = 0;
    bool flag = true;
    double max;

    while (in >> x)
    {
        out << fixed << setprecision(3) << x << endl;
        count++;

        if (flag)
        {
            max = x;
            flag = false;
        }
        else
        {
            if (x > max)
                max = x;
        }
    }

    out << "count=" << count << "/max=" << max << endl;
}

int main()
{
    {
        maximum("p4_test1.txt", "p4_test1_out.txt");
        show_file("p4_test1_out.txt");
    }
    cout << endl;
    {
        maximum("p4_test2.txt", "p4_test2_out.txt");
        show_file("p4_test2_out.txt");
    }
    cout << endl;

    {
        maximum("p4_test3.txt", "p4_test3_out.txt");
        show_file("p4_test3_out.txt");
    }
    cout << endl;

    {
        maximum("p4_test4.txt", "p4_test4_out.txt");
        show_file("p4_test4_out.txt");
    }
    return 0;
}
