#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        cout << "LETTER" << endl;
    else if (c >= '0' && c <= '9')
        cout << "DIGIT" << endl;
    else
        cout << "OTHER" << endl;
    return 0;
}
