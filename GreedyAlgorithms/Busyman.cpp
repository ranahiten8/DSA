#include <bits/stdc++.h>
using namespace std;
// activity selection problem

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t, s, n, e;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }
        sort(v.begin(), v.end(), cmp);

        //start picking activities
        int res = 1;
        int fin = v[0].second;
        //iterate over remaining activities
        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= fin)
            {
                res++;
                fin = v[i].second;
            }
        }

        cout << res << endl;
        v.clear();
    }

    return 0;
}