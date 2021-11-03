#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100000] = {0};
    int t;
    cin >> t;
    while (t--)
    {
        memset(arr, 0, sizeof arr);
        long long int n;
        for (long long int i = 0; i < n; i++)
        {
            string s;
            int rank;
            cin >> s >> rank;
            arr[rank]++;
        }
        int actual_rank = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            while (arr[i])
            {
                sum += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;
            }
        }

        cout << sum << endl;
    }

    return 0;
}