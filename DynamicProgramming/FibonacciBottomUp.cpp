#include <bits/stdc++.h>
using namespace std;
//complexity: O(n)
int fib(int n)
{
    int dp[100] = {0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibSpaceOptimized(int n)
{
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << fibSpaceOptimized(n);

    return 0;
}