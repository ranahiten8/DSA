#include <iostream>
using namespace std;
int profit(int n, int c, int *w, int *p)
{
    if (n == 0 or c == 0)
    {
        return 0;
    }
    int ans = 0;
    int inc, exc;
    inc = exc = 0;

    //including item
    if (w[n - 1] <= c)
    {
        inc = p[n - 1] + profit(n - 1, c - w[n - 1], w, p);
    }

    //excluding item
    exc = profit(n - 1, c, w, p);

    ans = max(inc, exc);
    return ans;
}

int main()
{
    int price[] = {40, 20, 30, 100};
    int weights[] = {1, 2, 3, 5};
    int n = 4; //no of items
    int c = 7; //capacity of bag
    cout<<profit(n,c,weights,price);
    return 0;
}