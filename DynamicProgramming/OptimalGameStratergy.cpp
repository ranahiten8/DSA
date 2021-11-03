#include <bits/stdc++.h>
using namespace std;

int optimum(int *arr, int i, int j, int dp[][100])
{
    if (i >= j)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    int op1 = arr[i] + min(optimum(arr, i + 2, j, dp), optimum(arr, i + 1, j - 1, dp));
    int op2 = arr[j] + min(optimum(arr, i, j - 2, dp), optimum(arr, i + 1, j - 1, dp));
    return dp[i][j] = max(op1, op2);
}

int main()
{
    int arr[] = {7, 3, 1, 6, 2, 8, 1, 0};
    int n = sizeof(arr) / sizeof(int);
    int dp[100][100] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    cout << optimum(arr, 0, n - 1, dp);

    return 0;
}