#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int pairs = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] <= d)
        {
            pairs++;
            i++;
        }
    }
    cout<<pairs;
    return 0;
}