#include <bits/stdc++.h>
using namespace std;

int profit(int *p, int n)
{
    int dp[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                dp[i][j] = 0;
            }
            else
            {
                int year = n - (j - i);
                dp[i][j] = max((year * p[i] + dp[i + 1][j]), (year * p[j] + dp[i][j - 1]));
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int p[] = {2, 3, 5, 1, 4};
    int n = sizeof(p) / sizeof(int);
    cout << profit(p, n);

    return 0;
}