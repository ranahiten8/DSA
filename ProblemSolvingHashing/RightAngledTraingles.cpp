#include <bits/stdc++.h>
using namespace std;

int totaltriangles(vector<pair<int, int>> v)
{
    unordered_map<int, int> Hx;
    unordered_map<int, int> Hy;

    for (int i = 0; i < v.size(); i++)
    {
        Hx[v[i].first]++;
        Hy[v[i].second]++;
    }

    int total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        total += (Hx[x] - 1) * (Hy[y] - 1);
    }

    return total;
}

int main()
{
    int p;
    cin >> p;
    vector<pair<int, int>> v;

    while (p--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    cout << totaltriangles(v);

    return 0;
}