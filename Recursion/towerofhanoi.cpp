#include <iostream>
using namespace std;

void towerofhanoi(int n, char src, char helper, char dest)
{

    if (n == 0)
    {
        return;
    }

    towerofhanoi(n - 1, src, dest, helper); // ye call hoga jabtak n=0 nhi hojata

    cout << "Move disc " << n << " from " << src << " to " << dest << endl;

    towerofhanoi(n - 1, helper, src, dest);
    
}

int main()
{
    int n;
    cin >> n;
    towerofhanoi(n, 'A', 'B', 'C');
    return 0;
}
