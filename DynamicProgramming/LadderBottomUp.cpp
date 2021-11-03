#include <bits/stdc++.h>
using namespace std;

int ways(int n, int k)
{
    int dp[1000] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                ans += dp[i - j];
            }
        }
        dp[i] = ans;
    }
    return dp[n];
}

int waysOptimized(int n, int k)
{
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << waysOptimized(n, k);

    return 0;
}