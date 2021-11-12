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
        vector<string> s;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i)
        {
            string m;
            cin >> m;
            s.push_back(m);
            v.push_back(make_pair(s[i][0] - 'A', s[i][2] - 'A'));
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                if(__builtin_popcount(v[i].first)==__builtin_popcount(v[j].second))
                {
                    v[i].first=-1;
                    v[j].second=-1;
                    break;
                }
            }
        }
        bool flag=1;
        for (int i = 0; i < n; ++i)
        {
            if(v[i].first!=-1 or v[i].second!=-1)
                flag=0;
            break;
        }
        cout<<flag;
    }
    return 0;
}