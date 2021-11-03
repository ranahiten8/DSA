#include <bits/stdc++.h>
using namespace std;

int soln(vector<int> A)
{
    int dp[200][200];
    int n = A.size() - 1;
    for (int i = 1; i < n; i++)
    {
        int r = 0, c = i;
        while (c < n)
        {
            int val = INT_MAX;
            for (int pivot = r; pivot < c; pivot++)
            {
                val = min(val, dp[r][pivot] + dp[pivot + 1][c] + A[r] * A[pivot + 1] * A[c + 1]);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }

    return dp[0][n - 1];
}

int main()
{
    vector<int> v{3, 1, 2, 4};
    cout<<soln(v);

    return 0;
}