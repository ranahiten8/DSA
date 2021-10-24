#include <iostream>
using namespace std;
// list having n numbers which are repeated twice and 1 number is unique
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {

        cin >> temp;
        ans = ans ^ temp;
    }
    cout << ans;
}