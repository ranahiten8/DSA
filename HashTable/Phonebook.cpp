#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, vector<int>> um;
    int t;
    cin >> t; // no of enteries
    while (t--)
    {
        cin.get();
        string str;
        getline(cin, str);
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        um[str] = v;
    }
    cout << endl;
    for (auto x : um)
    {
        cout << x.first << " : ";
        for (int i = 0; i < x.second.size(); i++)
        {
            cout << x.second[i] << " ";
        }
        cout << endl;
    }

    string s;
    cin >> s;
    if (um.count(s))
    {
        for (int i = 0; i < um[s].size(); i++)
        {
            cout << um[s][i] << " ";
        }
    }
    return 0;
}