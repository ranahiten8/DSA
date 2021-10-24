#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ideal[1000006], calling[1000006];
    deque<int> dq;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        dq.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ideal[i];
    }

    int totaltime = 0;
    int time;
    for (int i = 0; i < n; i++)
    {
        time = 1;
        if (ideal[i] == dq.front())
        {
            dq.pop_front();
        }
        else
        {
            while (ideal[i] != dq.front())
            {
                num = dq.front();
                dq.pop_front();
                dq.push_back(num);
                time = time + 1;
            }
            dq.pop_front();
        }
        totaltime = time + totaltime;
    }
    cout << totaltime;
    return 0;
}