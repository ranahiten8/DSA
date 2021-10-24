#include <iostream>
#include <stack>
using namespace std;

void PrimeSieve(int *p)
{

    // first mark all odd numbers as prime
    for (int i = 3; i < 100000; i += 2)
    {
        p[i] = 1;
    }
    for (long long int i = 3; i < 100000; i += 2)
    {
        if (p[i] == 1)
        {
            for (long long j = i * i; j <= 100000; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
    // Special case
    p[2] = 1;
    p[0] = p[1] = 0;
}

int main()
{
    int p[100005] = {0};
    PrimeSieve(p);

    int n, q, num;
    cin >> n;
    cin >> q;
    stack<int> a0, a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a0.push(num);
    }

    int i = 0;
    while (q)
    {
        if (p[i] == 0)
        {
            i++;
        }
        else if (p[i] == 1)
        {
            while (!a0.empty())
            {
                if (a0.top() % i == 0)
                {
                    num = a0.top();
                    b.push(num);
                    a0.pop();
                }
                else
                {
                    num = a0.top();
                    a.push(num);
                    a0.pop();
                }
            }
            a.swap(a0);
            while (!b.empty())
            {
                cout << b.top() << endl;
                b.pop();
            }
            i++;
            q--;
        }
    }
    while (!a0.empty())
    {
        cout << a0.top() << endl;
        a0.pop();
    }
    return 0;
}