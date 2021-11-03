#include <bits/stdc++.h>
using namespace std;
//complexity: O(n^2)
int profit(int *p, int i, int j, int y, int dp[][100])
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    int op1 = p[i] * y + profit(p, i + 1, j, y + 1, dp);
    int op2 = p[j] * y + profit(p, i, j - 1, y + 1, dp);
    dp[i][j] = max(op1, op2);
    return dp[i][j];
}

int main()
{
    int p[] = {2, 3, 5, 1, 4};
    int n = sizeof(p) / sizeof(int);
    int dp[100][100] = {0};
    cout << profit(p, 0, n - 1, 1, dp);

    return 0;
}