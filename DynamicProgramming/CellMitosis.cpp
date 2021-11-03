#include <bits/stdc++.h>
using namespace std;

long long mini(int n, int x, int y, int z)
{
    long long *dp = new long long[n + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        }
        else
        {
            dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;

    cout << mini(n, x, y, z);

    return 0;
}