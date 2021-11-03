#include <bits/stdc++.h>
using namespace std;

int count(int n, int *dp)
{
    if (n <= 2 )
    {
        return dp[n] = n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = count(n - 1, dp) + (n - 1) * count(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[1000];
    memset(dp, -1, sizeof(dp));
    cout << count(n, dp);

    return 0;
}