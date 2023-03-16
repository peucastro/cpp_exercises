#include <iostream>
using namespace std;

int array_size(const char arr[])
{
    int size = 0;
    while (arr[size] != '\0')
        size++;
    return size;
}

int diff_chars(const char str[])
{
    int count = 0;
    for (int i = 0; i < array_size(str); i++)
    {
        while (str[i] == str[i+1])
            count++;
    }
    return count;
}

void rle_encode(const char str[], char rle[])
{
    int count = 0;
    int str_index = 0;
    int rle_index = 0;

    for (int i = 0; i < diff_chars(str); i++)
    {
        while (str[str_index] == str[str_index + 1])
            count++;

        rle[rle_index] = count;
        rle[rle_index + 1] = str[i];
        rle_index += 2;
        count = 0;
        str_index = count;
    }
}

int main()
{
    char rle[10 + 1] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    rle_encode("abcde", rle);
    cout << rle << endl;
}
