// find out number of numbers between 1 to n which are divisible by any of the prime numbers
// less than 20
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
// Approach : Extract all possible subarrays , find the numbers divisible by each
// while simultaneously checking the size of subarray whether to add or subtract
int main()
{
    ll t;
    cin >> t;
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    while (t--)
    {
        ll n;
        cin >> n;
        ll subsets = (1 << 8) - 1; //no. of primes
        ll ans = 0;
        for (ll i = 1; i <= subsets; i++)
        {
            ll denom = 1ll;                     //variable for calculating the sum to divide n with
            ll setBits = __builtin_popcount(i); //counts the number of set bits
            for (ll j = 0; j <= 7; j++)
            {
                if (i & (1 << j))
                {
                    denom = denom * primes[j];
                }
            }
            if (setBits & 1)
            {
                ans += n / denom;
            }
            else
            {
                ans -= n / denom;
            }
        }
        cout << ans << endl;
    }

    return 0;
}