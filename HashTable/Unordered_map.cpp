#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m;

    // Insert
    m.insert(make_pair("mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;

    m.insert(p);

    m["banana"] = 20;

    // search
    string key = "banana";
    auto it = m.find(key);
    if (it != m.end())
    {
        cout << "price of fruit is " << m[key] << endl;
    }
    else
    {
        cout << "Fruit is not present " << endl;
    }


    // update
    // stores unique key only
    m["banana"] = 40; // this updates old value
    // alternative to find fnc
    // count returns 1 or 0

    //Does not update value
    m.insert(make_pair("mango", 200));

    if (m.count(key))
    {
        cout << "price of fruit is " << m[key] << endl;
    }
    else
    {
        cout << "Not present" << endl;
    }

    
    // erase
    m.erase(key);
    if (m.count(key))
    {
        cout << "price of fruit is " << m[key] << endl;
    }
    else
    {
        cout << "Not present" << endl;
    }

    //update
    key = "Apple";
    m["lichti"] = 80;
    m["Grape"] = 60;
    m[key] += 22;
    //sorted order
    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << (*it).second << endl;
    // }

    // OR
    for (auto p : m)
    {
        cout << p.first << " " << p.second<<endl;
    }

    return 0;
}