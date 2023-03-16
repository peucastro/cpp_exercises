#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
        size++;
    return size;
}

unsigned long pow(unsigned long base, unsigned long exp)
{
    unsigned long ans = 1;
    for (unsigned long i = 0; i < exp; i++)
        ans *= base;
    return ans;
}

unsigned long hstr_to_integer(const char hstr[])
{
    unsigned long ans = 0;
    unsigned long exp = 0;

    for (int k = array_size(hstr) - 1; k >= 0; k--)
    {
        unsigned long digit = 0;
        char d_str = toupper(hstr[k]);

        switch (d_str)
        {
        case '0':
            digit = 0;
            break;
        case '1':
            digit = 1;
            break;
        case '2':
            digit = 2;
            break;
        case '3':
            digit = 3;
            break;
        case '4':
            digit = 4;
            break;
        case '5':
            digit = 5;
            break;
        case '6':
            digit = 6;
            break;
        case '7':
            digit = 7;
            break;
        case '8':
            digit = 8;
            break;
        case '9':
            digit = 9;
            break;
        case 'A':
            digit = 10;
            break;
        case 'B':
            digit = 11;
            break;
        case 'C':
            digit = 12;
            break;
        case 'D':
            digit = 13;
            break;
        case 'E':
            digit = 14;
            break;
        case 'F':
            digit = 15;
            break;
        }
        ans += digit * pow(16, exp);
        exp++;
    }
    return ans;
}

int main()
{
    cout << hstr_to_integer("CafeBabe2022") << endl;
}
