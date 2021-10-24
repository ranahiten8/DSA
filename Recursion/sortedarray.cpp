#include <iostream>
using namespace std;

bool sorted(int *a, int n, int i)
{

    if (i == n - 1)
    {
        return true;
    }

    if (a[i] < a[i + 1] and sorted(a, n, i + 1))
    {
        return true;
    }
    return false;
}

int main()
{
    int a[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool ans = sorted(a, n, 0);
    if (ans == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}