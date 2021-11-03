#include <bits/stdc++.h>
using namespace std;

int ways(int n, int k, int *dp)
{
    if (n == 0)
    {
        return 1;
    }
    int ans = 0;
    if (dp[n] != 0)
    {
        return dp[n];
    }
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ans += ways(n - i, k, dp);
        }
    }
    return dp[n] = ans;
}


int main()
{
    int n, k;
    cin >> n >> k;
    int dp[1000] = {0};
    cout << ways(n, k, dp);

    return 0;
}