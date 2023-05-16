#include "Person.h"
#include <iostream>
using namespace std;

class Student : public Person
{
public:
    Student(int id, const string &name, const string &course)
        : Person(id, name) { course_ = course; }

    const string &course() const { return course_; }

    virtual string to_string() const
    {
        ostringstream ans;
        ans << Person::to_string() << '/' << course_;
        return ans.str();
    }

private:
    string course_;
};

class ErasmusStudent : public Student
{
public:
    ErasmusStudent(int id, const string &name, const string &course, const string &country) : Student(id, name, course) { country_ = country; }

    const string &country() const { return country_; }

    virtual string to_string() const
    {
        ostringstream ans;
        ans << Student::to_string() << '/' << country_;
        return ans.str();
    }

private:
    string country_;
};

int main()
{
    {
        const Person &p = Student(123, "Manuel Dias", "LEIC");
        cout << p.id() << ' ' << p.name() << '\n';
    }
    {
        const Student &s = ErasmusStudent(124, "John Zorn", "LXPTO", "United States");
        cout << s.id() << ' ' << s.name() << ' ' << s.course() << '\n';
    }
    {
        Student s(123, "Manuel Dias", "LEIC");
        cout << s.id() << ' ' << s.name() << ' ' << s.course() << '\n';
    }
    {
        ErasmusStudent es(124, "John Zorn", "LXPTO", "United States");
        cout << es.id() << ' ' << es.name() << ' ' << es.course() << ' ' << es.country() << '\n';
    }
    {
        Person p(125, "Marie Curie");
        Student s(126, "Ada Lovelace", "LEIC");
        ErasmusStudent es(127, "Grace Hopper", "LXPTO", "United States");
        cout << p.to_string() << ' ' << s.to_string() << ' ' << es.to_string() << '\n';
    }
    return 0;
}
