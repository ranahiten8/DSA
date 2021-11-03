#include <bits/stdc++.h>
using namespace std;

int steps(int n, int *dp)
{
    if (n == 1)
    {
        return 0;
    }
    int three = INT_MAX, two = INT_MAX, one = INT_MAX;
    //lookUP
    if (dp[n] != 0)
    {

        return dp[n];
    }
    if (n % 3 == 0)
    {
        three = steps(n / 3, dp);
    }
    if (n % 2 == 0)
    {
        two = steps(n / 2, dp);
    }
    one = steps(n - 1, dp);
    int ans = min(three, min(two, one)) + 1;
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << steps(n, dp);

    return 0;
}