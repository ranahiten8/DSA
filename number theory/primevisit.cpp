#include <iostream>
using namespace std;
#define ll long long

int primesieve(int *p)
{
    //mark all odds as prime
    for (int i = 3; i <= 10000; i += 2)
    {
        p[i] = 1;
    }
    //seive
    for (ll i = 3; i <= 10000; i += 2)
    {
        if (p[i] == 1)
        {
            for (ll j = i * i; j <= 10000; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
    //special cases
    p[2] = 1;
    p[1] = p[0] = 0;
    return 0;
}

int main()
{
    int p[10005] = {0};
    primesieve(p);

    int csum[10005] = {0};
    for (int i = 1; i <= 10005; i++)
    {
        csum[i] = csum[i - 1] + p[i];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << csum[b] - csum[a - 1] << endl;
    }
    return 0;
}