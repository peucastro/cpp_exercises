#include <iostream>
#include <string>
#include <set>
#include "Book.h"
using namespace std;

int main()
{
    {
        Book b;
        if (!(b.import("book_01.txt")))
            cout << "book not found! \n";
        set<string> words = {"C++", "linux", "computer"};
        b.build_index(words);
        b.show_index();
    }
    {
        Book b;
        if (!(b.import("book_02.txt")))
            cout << "book not found! \n";
        set<string> words = {"C++", "program", "computer", "windows"};
        b.build_index(words);
        b.show_index();
    }
    {
        Book b;
        if (!(b.import("book_03.txt")))
            cout << "book not found! \n";
        set<string> words = {"linux", "program", "cpu"};
        b.build_index(words);
        b.show_index();
    }
    {
        Book b;
        if (!(b.import("book_04.txt")))
            cout << "book not found! \n";
        set<string> words = {"computer", "program", "file", "windows"};
        b.build_index(words);
        b.show_index();
    }
    {
        Book b;
        if (!(b.import("book_05.txt")))
            cout << "book not found! \n";
        set<string> words = {"linux", "byte", "cpu"};
        b.build_index(words);
        b.show_index();
    }
    return 0;
}
