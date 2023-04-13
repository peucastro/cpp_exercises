#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Person
{
public:
    Person(const string &name, const string &address, const string &phone);
    string get_name() const;
    string get_address() const;
    string get_phone() const;

private:
    string name_;    // Name
    string address_; // Address
    string phone_;   // Phone
};

Person::Person(const string &name, const string &address, const string &phone)
{
    name_ = name;
    address_ = address;
    phone_ = phone;
}

string Person::get_name() const
{
    return name_;
}

string Person::get_address() const
{
    return address_;
}

string Person::get_phone() const
{
    return phone_;
}

void show_persons_data(const vector<Person> &persons)
{
    cout << "[\n";
    for (const auto &p : persons)
    {
        cout << "  " << p.get_name()
             << " : " << p.get_address()
             << " : " << p.get_phone() << '\n';
    }
    cout << "]\n";
}

void read_persons_data(const string &file_name, vector<Person> &persons)
{
    ifstream in(file_name);
    string line;
    vector<string> aux;

    while (getline(in, line))
    {
        aux.push_back(line);
        if (aux.size() == 3)
        {
            persons.push_back(Person(aux[0], aux[1], aux[2]));
            aux.clear();
        }
    }
}

void sort_persons_by_name(vector<Person> &persons)
{
    int size = persons.size();
    Person tmp("NAME", "ADDRESS", "PHONE");

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (persons[j + 1].get_name()[0] < persons[j].get_name()[0])
            {
                tmp = persons[j];
                persons[j] = persons[j + 1];
                persons[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    {
        vector<Person> persons{
            Person("Pedro Miguel Faria", "Rua de Santa Catarina, 1234, Porto", "911123456"),
            Person("Maria Roberta Fernandes", "Rua do Santo Silva, 4321, Porto", "987654321")};
        show_persons_data(persons);
    }
    {
        vector<Person> persons;
        read_persons_data("persons-1.txt", persons);
        show_persons_data(persons);
    }
    {
        vector<Person> persons;
        read_persons_data("persons-1.txt", persons);
        sort_persons_by_name(persons);
        show_persons_data(persons);
    }
    {
        vector<Person> persons;
        read_persons_data("persons-2.txt", persons);
        sort_persons_by_name(persons);
        show_persons_data(persons);
    }
    return 0;
}
