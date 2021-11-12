#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[9000];
    int n, i, val, diff;
    while (1)
    {
        int diff = 0;
        int max_load = 0, load = 0;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            load += arr[i];
        }
        if (load % n != 0)
        {
            cout << -1 << endl;
            continue;
        }
        //find load which is to be divided equally
        load = load / n;
        diff = 0;
        //greedy step
        for (int i = 0; i < n; i++)
        {
            //find difference b/w final load to be assigned and current load
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout << max_load << endl;
    }

    return 0;
}