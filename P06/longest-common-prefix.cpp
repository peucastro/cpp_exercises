#include <iostream>
#include <vector>
using namespace std;

string longest_prefix(const vector<string> &v)
{
    string longest = v[0];

    for (long unsigned int i = 1; i < v.size(); i++)
    {
        for (long unsigned int j = 0; j < v[i].size(); j++)
        {
            if (j >= longest.size())
                break;
            else if (longest[j] != v[i][j])
            {
                longest = longest.substr(0, j);
            }
        }
    }
    return longest;
}

int main()
{
    cout << "\"" << longest_prefix({"apple", "apply", "ape", "april"}) << "\"\n";
    cout << "\"" << longest_prefix({"ap", "apple", "apply", "ape", "april", "aq", "x"}) << "\"\n";
    cout << "\"" << longest_prefix({
                        "geezer",
                        "geeksforgeeks",
                        "geeks",
                        "geek",
                    })
         << "\"\n";
    cout << "\"" << longest_prefix({"sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations"}) << "\"\n";
    cout << "\"" << longest_prefix({"symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella"}) << "\"\n";
    return 0;
}
