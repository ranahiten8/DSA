#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int count(int m, int n, int dp[][1001])
{
    if (dp[0][0] == -1)
    {
        return 0;
    }

    for (int j = 0; j < n; j++)
    {
        if (dp[0][j] == -1)
        {
            break;
        }
        dp[0][j] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (dp[i][0] == -1)
        {
            break;
        }
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i][j] == -1)
            {
                continue;
            }
            dp[i][j] = 0;
            if (dp[i][j - 1] != -1)
            {
                dp[i][j] = dp[i][j - 1] % MOD;
            }
            if (dp[i - 1][j] != -1)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }
    if (dp[m - 1][n - 1] == -1)
    {
        return 0;
    }

    return dp[m - 1][n - 1];
}

int main()
{
    int m, n, p;
    cin >> m >> n >> p;
    int dp[1001][1001];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    cout << count(m, n, dp) << endl;
    return 0;
}