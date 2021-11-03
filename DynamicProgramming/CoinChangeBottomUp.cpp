#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int *c, int t)
{
    int dp[1000] = {0};
    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MAX;
        for (int j = 0; j < t; j++)
        {
            if (i - c[j] >= 0)
            {
                ans = min(ans, dp[i - c[j]] + 1);
            }
        }
        dp[i] = ans;
    }

    return dp[n];
}

int main()
{
    int N = 15;
    int coins[] = {1, 7, 10};
    int T = sizeof(coins) / sizeof(int);

    cout << minCoins(N, coins, T) << endl;

    return 0;
}