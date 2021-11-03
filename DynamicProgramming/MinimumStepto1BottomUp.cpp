#include <bits/stdc++.h>
using namespace std;
//done wrong in video
int step(int n)
{
    int arr[1000] = {0};
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        if (i % 3 == 0)
        {
            op1 = arr[i / 3];
        }
        if (i % 2 == 0)
        {
            op2 = arr[i / 2];
        }
        op3 = arr[i - 1];
        arr[i] = min(op1, min(op2, op3)) + 1;
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << step(n);

    return 0;
}