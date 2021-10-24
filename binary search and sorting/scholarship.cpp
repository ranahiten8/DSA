#include <iostream>
using namespace std;

bool maxstudent(int n, int m, int x, int y, int max)
{
    if ((max * x) <= m + (n - max) * y)
    {
        return true;
    }
    return false;
}

int main()
{
    int n, m, x, y; //no of students, coupon available, coupons required, paid coupons
    cin >> n >> m >> x >> y;

    int s, e, mid;

    s = m / x;
    e = n;
    int ans = -1;

    while (s <= e)
    {
        int mid = (e + s) / 2;
        bool possible = maxstudent(n, m, x, y, mid);

        if (possible)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout<<ans;

    return 0;
}