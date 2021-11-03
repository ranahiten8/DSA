#include <bits/stdc++.h>
using namespace std;

int rodTopDown(int *prices, int n, int *dp)
{
    if (n <= 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    if (dp[n] != 0)
    {
        return dp[n];
    }
    for (int i = 0; i < n; i++)
    {
        int current_ans = prices[i] + rodTopDown(prices, n - (i + 1), dp);
        ans = max(ans, current_ans);
    }
    return dp[n] = ans;
}

int rodBottomUp(int *prices, int n, int *dp)
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int current = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            int ans = prices[j] + dp[i - (j + 1)];
            current = max(current, ans);
        }
        dp[i] = current;
    }
    return dp[n];
}

int main()
{
    int prices[] = {5, 6, 7, 7};

    int n = sizeof(prices) / sizeof(int);
    int dp[100] = {0};
    cout << rodBottomUp(prices, n, dp) << endl;
    return 0;
}