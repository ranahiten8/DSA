#include <iostream>
using namespace std;

// int power(int a, int n)         // this is not efficient way for large values O(n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     return a * power(a, n - 1);
// }

int fastpower(int a, int n) //this is efficient way O(log(n)) complexity
{
    if (n == 0)
    {
        return 1;
    }

    /*int smallans=fastpower(a,n/2)*fastpower(a,n/2)....this will take more time so better
    is to store recursive f(n) in a variable small ans and multiply it by itself*/

    int smallans = fastpower(a, n / 2);
    smallans *= smallans;

    if (n & 1) // if no is odd ans=a*(a^(n/2))^2
    {
        return smallans * a;
    }
    return smallans; //else ans=(a^(n/2))^2
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << fastpower(a, n) << endl;
    return 0;
}