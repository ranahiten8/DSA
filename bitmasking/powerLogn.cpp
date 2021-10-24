#include <iostream>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    int ans = 1;
    while (p > 0)
    {
        int lastbit = (p & 1);
        if (lastbit)
        {
            ans *= n;
        }
        n = n * n;
        p = p >> 1;
    }
    cout << ans;
}