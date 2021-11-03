#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> leftheap;
    priority_queue<int, vector<int>, greater<int>> rightheap;

    int d;
    cin >> d;
    leftheap.push(d);

    float med = d;
    cout << "Median-> " << med << " ";
    cin >> d;
    // input all elements
    while (d != -1)
    {
        if (leftheap.size() > rightheap.size())
        {
            if (d > med)
            {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else
            {
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }
        else if (leftheap.size() == rightheap.size())
        {
            if (d < med)
            {
                leftheap.push(d);
                med = leftheap.top();
            }
            else
            {
                rightheap.push(d);
                med = leftheap.top();
            }
        }
        else
        {
            if (d > med)
            {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            else
            {
                leftheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }
        cout << "Median-> " << med << " ";
        cin >> d;
    }

    return 0;
}