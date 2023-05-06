#include <cctype>
#include <iostream>
using namespace std;

int main()
{
    int n;
    char c;
    int letterCount = 0, digitCount = 0, otherCount = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (isalpha(c))
            letterCount++;
        else if (isdigit(c))
            digitCount++;
        else
            otherCount++;
    }
    cout << letterCount << " " << digitCount << " " << otherCount;
    return 0;
}
