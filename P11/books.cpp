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
