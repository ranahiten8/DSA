#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int f, r, cs, ms; //front rear current size max size

public:
    queue(int ds = 5)
    {
        arr = new int[ds];
        f = 0;
        ms = ds;
        cs = 0;
        r = ms - 1;
    }
    bool empty()
    {
        return cs == 0;
    }
    bool full()
    {
        return cs == ms;
    }
    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }
    void pop()
    {
        if (!empty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }
    void front()
    {
        cout << arr[f];
    }
    ~queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
    queue q(10);
    for (int i = 1; i <= 6; i++)
    {
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);
    while (!q.empty())
    {
        q.front();
        cout << " ";
        q.pop();
    }
}
