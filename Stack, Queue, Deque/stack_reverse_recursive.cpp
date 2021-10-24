#include <iostream>
#include <stack>
using namespace std;

void insertATbottom(stack<int> &s, int x)
{
    //base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    //rec case
    int data = s.top();
    s.pop();
    insertATbottom(s, x);
    s.push(data);
}

void reverse(stack<int> &s)
{
    //base case
    if (s.empty())
    {
        return;
    }

    //otherwise
    //pop out the top element and insert it at the bottom of 'reversed smaller stack'
    int x = s.top();
    s.pop();
    reverse(s);
    insertATbottom(s, x);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}