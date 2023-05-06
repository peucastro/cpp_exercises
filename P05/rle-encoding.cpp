#include <iostream>
using namespace std;

void int_to_str(int n, char str[], int &pos)
{
    int d = 0;
    for (int i = n; i != 0; i = i / 10)
    {
        d++;
    }
    for (int i = d, j = n; i > 0; i--)
    {
        str[pos + i - 1] = '0' + j % 10;
        j = j / 10;
    }
    pos = pos + d;
}

void rle_encodeAux(int n, char c, char rle[], int &pos)
{
    if (n == 0)
    {
        return;
    }
    int_to_str(n, rle, pos);
    rle[pos] = c;
    pos++;
}

void rle_encode(const char str[], char rle[])
{
    int i = 0;
    int j = 0;
    char c = 0;
    int n = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            n++;
        }
        else
        {
            rle_encodeAux(n, c, rle, j);
            n = 1;
            c = str[i];
        }
        i++;
    }
    rle_encodeAux(n, c, rle, j);
    rle[j] = '\0';
}

int main(void)
{
    {
        char rle[1] = {-1};
        rle_encode("", rle);
        cout << rle << endl;
    }
    {
        char rle[2 + 1] = {-1, -1, -1};
        rle_encode("a", rle);
        cout << rle << endl;
    }
    {
        char rle[10 + 1] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        rle_encode("abcde", rle);
        cout << rle << endl;
    }
    {
        char rle[9 + 1] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        rle_encode("aaaaabbbbbbbbbbbcccd", rle);
        cout << rle << endl;
    }
    {
        char rle[3 + 1] = {-1, -1, -1, -1};
        rle_encode("xxxxxxxxxxxxxxxxxxxx", rle);
        cout << rle << endl;
    }

    cout << endl;
}
