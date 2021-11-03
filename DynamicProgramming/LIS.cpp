#include <bits/stdc++.h>
using namespace std;

int longest(int *arr, int n)
{
    int dp[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;
    }
    int lis = 0;
    for (auto x : dp)
    {
        lis = max(lis, x);
    }
    return lis;
}
// dp is actually the longets subsequence
int longestBetter(int *arr, int n)
{
    int dp[n + 1];
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++)
    {
        for (int length = 0; length < n; length++)
        {
            if (dp[length] < arr[i] && arr[i] < dp[length + 1])
            {
                dp[length + 1] = arr[i];
            }
        }
    }
    int lis = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            lis = i;
        }
    }
    return lis;
}

int longestBest(int *arr, int n)
{
    int dp[n + 1];
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++)
    {
        int len = upper_bound(dp, dp + n + 1, arr[i]) - dp;
        if (dp[len - 1] < arr[i] && arr[i] < dp[len])
        {
            dp[len] = arr[i];
        }
    }
    int lis = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            lis = i;
        }
    }
    return lis;
}

int main()
{
    int arr[] = {0};
    int n = sizeof(arr) / sizeof(int);
    cout << longestBest(arr, n);
    return 0;
}