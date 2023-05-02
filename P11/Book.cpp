#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include "Book.h"
#include "Page.h"

using namespace std;

Book::Book() {}

//! Imports book contents from text file ‘filename’
bool Book::import(const string &filename)
{
    ifstream f(filename);
    if (f.fail())
    {
        return false;
    }
    else
    {
        string line;
        Page page;
        while (getline(f, line))
        {
            if (line == "<PAGE>")
            {
                this->book_.push_back(page);
                page.clear();
            }
            else
                page.add_line(line);
        }
        return true;
    }
}

//! Builds ‘index’ for the ‘words’ received as parameter
void Book::build_index(const set<string> &words)
{
    size_t curr_page = 0;
    for (Page page : book_)
    {
        curr_page++;
        for (size_t i = 0; i < page.get_num_lines(); i++)
        {
            istringstream input(page.get_line(i));
            string word;

            while (input >> word)
            {
                for (string w : words)
                {
                    if (w == word)
                    {
                        bool find = false;
                        for (auto &p : index_)
                        {
                            if (p.first == word)
                            {
                                find = true;
                                p.second.insert(curr_page);
                            }
                        }
                        if (!find)
                        {
                            std::pair<std::string, std::set<size_t>> new_pair(word, {curr_page});
                            index_.insert(new_pair);
                        }
                    }
                }
            }
        }
    }
}

//! Shows book
void Book::show_book() const
{
    size_t page_num = 0;
    for (const Page &page : book_)
    {
        cout << "PAGE " << ++page_num << endl;
        page.show();
    }
    cout << endl;
}

//! Shows book index
void Book::show_index() const
{
    cout << "/ ";
    for (const auto &i : index_)
    {
        cout << i.first << ": ";
        for (const auto &p : i.second)
            cout << p << " ";
        cout << "/ ";
    }
    cout << endl;
}
