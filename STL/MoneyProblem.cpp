#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a <= b;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);
    int k, m;

    cin >> k;
    m = k;

    while (m > 0)
    {
        auto lb = lower_bound(coins, coins + n, m, compare) - coins - 1;
        m = m - coins[lb];
        cout << coins[lb] << endl;
    }

    return 0;
}