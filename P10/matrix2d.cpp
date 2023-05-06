#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_vector(const vector<vector<int>> &v)
{
    cout << "{";
    for (const auto &line : v)
    {
        cout << "{ ";
        for (const auto &elem : line)
            cout << elem << ' ';
        cout << "}";
    }
    cout << "}";
}

bool max_filter(vector<vector<int>> &v, int n)
{
    int matrix_size = v.size();
    int row_size = v[0].size();

    if (n == 0 || n % 2 == 0 || matrix_size < n || row_size < n)
        return false;
        
    vector<vector<int>> copy = v;
    for (int line = 0; line < matrix_size; line++)
    {
        for (int column = 0; column < row_size; column++)
        {
            vector<int> neighbourhood;
            for (int i = max(0, line - (n / 2)); i <= min(line + (n / 2), matrix_size - 1); i++)
            {
                for (int j = max(0, column - (n / 2)); j <= min(column + (n / 2), row_size - 1); j++)
                {
                    neighbourhood.push_back(v[i][j]);
                }
            }
            sort(neighbourhood.begin(), neighbourhood.end(), greater<int>());
            copy[line][column] = neighbourhood[0];
        }
    }
    v = copy;
    return true;
}

int main()
{
    {
        vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        bool row_size = max_filter(v, 3);
        cout << boolalpha << row_size;
        show_vector(v);
        cout << endl;
    }
    {
        vector<vector<int>> v =
            {{8, 5, 4, 2, 1},
             {1, 2, 4, 5, 9},
             {3, 6, 3, 7, 3},
             {5, 7, 8, 1, 4},
             {9, 1, 2, 6, 5}};
        bool row_size = max_filter(v, 3);
        cout << boolalpha << row_size;
        show_vector(v);
        cout << endl;
    }
    {
        vector<vector<int>> v = {{8, 5, 4, 2, 1}, {9, 1, 2, 6, 5}};
        bool row_size = max_filter(v, 3);
        cout << boolalpha << row_size;
        show_vector(v);
        cout << endl;
    }
    {
        vector<vector<int>> v =
            {{-8, -5, 4, 2, 1, -1, 7},
             {-1, -2, 4, 5, 9, 0, 4},
             {-3, 6, -3, -7, 3, -10, -7},
             {5, 7, 8, 1, 4, -2, -31},
             {-9, 1, -2, 6, 5, -5, -16}};
        bool row_size = max_filter(v, 3);
        cout << boolalpha << row_size;
        show_vector(v);
        cout << endl;
    }
    {
        vector<vector<int>> v =
            {{-8, -5, 4, 2, 1, -1, 7},
             {-1, -2, 4, 5, 9, 0, 4},
             {-3, 6, -3, -7, 3, -10, -7},
             {5, 7, 8, 1, 4, -2, -31},
             {-9, 1, -2, 6, 5, -5, -16}};
        bool row_size = max_filter(v, 5);
        cout << boolalpha << row_size;
        show_vector(v);
        cout << endl;
    }
    return 0;
}
