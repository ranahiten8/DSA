#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int *c, int t, int *dp)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    if (dp[n] != 0)
    {
        return dp[n];
    }
    for (int i = 0; i < t; i++)
    {
        if (n - c[i] >= 0)
        {
            int subprob = minCoins(n - c[i], c, t, dp);
            ans = min(ans, subprob + 1);
        }
    }
    return dp[n] = ans;
}

int main()
{
    int N = 12;
    int coins[] = {1, 7, 10};
    int T = sizeof(coins) / sizeof(int);
    int dp[1000] = {0};

    cout << minCoins(N, coins, T, dp) << endl;

    return 0;
}