#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
    }

    return 0;
}