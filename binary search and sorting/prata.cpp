
#include <iostream>
#include <cmath>
using namespace std;
bool can_make(int *arr, int p, int n, int min_time)
{
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 1, sum = 0;
        while (sum + arr[i] * j <= min_time)
        {
            sum += arr[i] * j;
            ct++;
            j++;
            if (ct >= p)
                return true;
        }
        if (ct >= p)
            return true;
    }

    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int s = 0;
        int ans = -1;
        int e = (2 * arr[0] + (p - 1) * arr[0]) * p / 2;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            bool banpaye = can_make(arr, p, n, mid);
            if (banpaye)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        cout << ans << endl;
    }
}