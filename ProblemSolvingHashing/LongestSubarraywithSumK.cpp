#include <bits/stdc++.h>
using namespace std;

int checksum(int *arr, int n, int k)
{
    unordered_map<int, int> um;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == k)
        {
            len = i + 1;
        }
        if (um.count(pre - k))
        {
            len = max(len, i - um[pre - k]);
        }
        if (!um.count(pre))
        {
            um[pre] = i;
        }
    }

    return len;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << checksum(arr, n, k);

    return 0;
}