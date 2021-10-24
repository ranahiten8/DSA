#include <iostream>
using namespace std;

int main()
{
    string x;
    cin >> x;
    bool flag = false;
    for (int i = 0; i < x.length(); i++)
    {
        if (i == 0 && ((x[i] - '0') == 9))//so that 1st digit doesnt become 0
        {
            flag = true;
            continue;
        }
        if ((x[i] - '0') >= 5)
        {
            x[i] = (9 - (x[i] - '0')) + '0';
        }
    }
    cout << x << endl;
    return 0;
}