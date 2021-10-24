#include <iostream>
#include <cstring>
using namespace std;
#define ll long

ll a[1000005], pre[1000005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(pre, 0, sizeof(pre)); //sets the memory block from pre till end of pre as 0

        pre[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n) % n;// in case of negative values we add n 
            pre[sum]++; //storing values of sum in frequency array
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll m = pre[i];
            ans += (m) * (m - 1) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}