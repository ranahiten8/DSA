#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string no)
    {
        firstname = f;
        lastname = l;
        rollno = no;
    }

    bool operator==(const Student &s) const
    {
        return rollno == s.rollno;
    }
};

class Hashfn
{
public:
    size_t operator()(const Student &s) const
    {
        return s.firstname.length() + s.lastname.length();
    }
};

int main()
{
    unordered_map<Student, int, Hashfn> um;
    Student s1("Prateek", "Nigga", "010");
    Student s2("Prateek", "Nigga", "023");
    Student s3("Nishca", "Ver", "030");
    Student s4("Nish", "Verma", "011");
    Student s5("Shee", "Esssh", "089");

    um[s1] = 100;
    um[s2] = 120;
    um[s3] = 130;
    um[s4] = 90;
    um[s5] = 60;

    for (auto x : um)
    {
        cout << x.first.firstname << " " << x.first.rollno << "Marks "<<x.second<< endl;
    }
    return 0;
}