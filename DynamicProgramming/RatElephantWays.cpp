#include <bits/stdc++.h>
using namespace std;

int elephant(int r, int c, int dp[][100])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int rowsum = 0, colsum = 0;
                for (int k = 0; k < i; k++)
                {
                    rowsum += dp[k][j];
                }
                for (int k = 0; k < j; k++)
                {
                    colsum += dp[i][k];
                }
                dp[i][j] = rowsum + colsum;
            }
        }
    }

    return dp[r-1][c-1];
}

int rat(int r, int c, int dp[][100])
{
    // if cell blocked then mark it as 0
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 1;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[r - 1][c - 1];
}

int main()
{
    int r, c;
    cin >> r >> c;
    int dp[100][100];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            dp[i][j] = 0;
        }
    }

    cout << elephant(r, c, dp);

    return 0;
}