#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find the Next Greater Element(NGE) time-O(n) space-O(n)
void printNGE(int a[], int n)
{
    stack<int> s;
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--) // circular h isliye 2n times
    {
        while (!s.empty() && a[i % n] >= s.top())
        {
            s.pop();
        }
        if (i < n)
        {
            if (!s.empty())
            {
                ans[i] = s.top();
            }
            else
            {
                ans[i] = -1;
            }
        }
        s.push(a[i % n]);
    }

    //print
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n, num;
    int a[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    printNGE(a, n);

    return 0;
}
