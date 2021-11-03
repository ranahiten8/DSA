#include <bits/stdc++.h>
using namespace std;

int checksum(int *arr, int n)
{
    unordered_map<int, int> um;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == 0)
        {
            len = max(len, i + 1);
        }
        if (um.count(pre))
        {
            len = max(len, i - um[pre]);
        }
        else
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

    cout << checksum(arr, n);

    return 0;
}