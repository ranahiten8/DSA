#include <iostream>
#include <algorithm>
using namespace std;

/*this bool function checks if we can place all c no of cows in stalls at min separation
for that particular min_sep/mid value*/
bool canplace_cow(long x[], int n, int c, int min_sep)
{
    //place 1st cow at 1st stall
    int prev_cow = x[0];

    int cow_counter = 1;

    for (int i = 1; i < n; i++)
    {
        if (x[i] - prev_cow >= min_sep)
        {
            prev_cow = x[i];
            cow_counter++;
            if (cow_counter == c)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, c;
    long x[1000];

    //n number of stalls, c number of cows
    cin >> n >> c;

    //input values of coordinates of stalls in increasing order
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);

    //binary search algo
    int s, e, mid;
    s = 0;
    e = x[n - 1] - x[0];

    int ans = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        // store value returned by can place cow in a variable
        bool cow_rakhpaye = canplace_cow(x, n, c, mid);

        if (cow_rakhpaye)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans;

    return 0;
}
