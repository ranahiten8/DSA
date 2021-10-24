#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

bool check(ll n,ll k,ll mid)
{
    if(pow(mid,k)<=n)
    {
        return true;
    }
    return false;
}

int main()
{
    ll t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll x;

        ll s, e, mid;
        s = 1;
        e = n;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            bool possible = check(n,k,mid);
            if (possible)
            {
                x = mid;
                s = mid + 1;
            }
            else
            {
                e=mid-1;
            }
        }
        cout<<x<<endl;
    }
    return 0;
}