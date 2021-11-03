#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[10] = {1, 5, 3};
    int arr2[10] = {2, 6, 7};

    sort(arr1, arr1 + 3);
    sort(arr2, arr2 + 3);
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        res += abs(arr1[i] - arr2[i]);
    }

    cout<<res;

    return 0;
}