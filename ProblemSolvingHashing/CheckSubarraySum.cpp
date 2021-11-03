#include <bits/stdc++.h>
using namespace std;

// bool checksum(int *arr, int n)
// {
//     unordered_set<int> s;
//     int pre = 0;

//     for (int i = 0; i < n; i++)
//     {
//         pre += arr[i];
//         if(pre == 0 or s.find(pre) != s.end()){
//             return true;
//         }
//         s.insert(pre);
//     }

//     return false;
// }

// OR

bool checksum(int *arr, int n)
{
    unordered_map<int, bool> um;
    int pre = 0;
    for(int i=0;i<n;i++){
        pre += arr[i];
        if(pre == 0 or um.count(pre)){
            return true;
        }
        um[pre] = true;
    }

    return false;
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

    if (checksum(arr, n))
    {
        cout << "Yes";
    }

    else
    {
        cout << "NO";
    }

    return 0;
}