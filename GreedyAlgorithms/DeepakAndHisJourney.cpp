#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            int c, l;
            cin >> c >> l;
            v.push_back(make_pair(c, l));
        }
        long long int cost = 0;
        for (int i = 0; i < n; i++)
        {
            pq.push(v[i].first);
            cost += pq.top() * v[i].second;
        }
        cout << cost << endl;
    }

    return 0;
}