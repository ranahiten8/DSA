// top k person with age
#include <bits/stdc++.h>
using namespace std;

class person
{
public:
    string name;
    int age;

    person(string n, int a)
    {
        name = n;
        age = a;
    }
};

// STL only accepts class as a parameter and no function so we make a compare class
class personcompare
{
public:
    bool operator()(person a, person b)
    {
        return a.age > b.age;
    }
};

int main()
{
    int n;
    cin >> n;

    priority_queue<person, vector<person>, personcompare> pq;

    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        person p(name, age);
    }

    // we use this priority queue if we want to extract top k elements instead of sorting them
    // sorting will take nLogn but pq will take kLogn
    int k = 3;
    for (int i = 0; i < k; i++)
    {
        person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }

    return 0;
}