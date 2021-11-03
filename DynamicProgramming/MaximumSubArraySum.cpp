#include <bits/stdc++.h>
using namespace std;

int maxSum(int a[], int n)
{
    int max_so_far = INT_MIN;
    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        max_so_far = max(dp[i], max_so_far);
    }

    return max_so_far;
}

int main()
{
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << maxSum(arr, n);

    return 0;
}