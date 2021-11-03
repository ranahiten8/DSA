#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    int arr[100][100];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int dp[100][100];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = arr[0][0];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[0][j - 1] + arr[0][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][0] + arr[i][0];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
            }
        }
    }

    cout<< dp[r - 1][c - 1];

    return 0;
}