#include <iostream>
using namespace std;

bool paint(int k, int n, int b[100], int mintime)
{
    int painterused = 1;
    int timectr = 0;
    for (int i = 0; i < n; i++)
    {
        if (timectr + b[i] > mintime)
        {
            painterused += 1;
            if (painterused > k)
            {
                return false;
            }
        }
        else
        {
            timectr += b[i];
        }
    }
    return true;
}

int main()
{
    int n, k, t, b[100];
    cin >> n >> k >> t; //no of boards ,no of painters ,time taken to paint 1 board
    int sum = 0;

    //try to input in ascending order
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum += b[i];
    }

    //binary algo
    int s, e, mid;
    s = b[n-1];
    e = sum;
    int ans = -1;

    while (s <= e)
    {
        mid = (s + e) / 2;
        bool possible = paint(k, n, b, mid);
        if (possible)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << t*ans;
}