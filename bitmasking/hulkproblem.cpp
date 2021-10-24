#include <iostream>
#include <cmath>
using namespace std;

/*The Planet Earth is under a threat from the aliens of the outer space and the Marvel Avengers
team is busy fighting against them.Meanwhile, The Incredible Hulk has to defeat an enemy who is
N steps above the level where he is standing (assume it as the 0th level). Hulk, because of his
incredible jumping ability can take jumps in power of 2. In order to defeat the enemy as quickly
as possible he has to reach the Nth step in minimum moves possible. Help Hulk to find the same
and contribute in saving the Mother Earth*/


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, jump, k, counter = 0;
        cin >> n;
        while (n > 0)
        {
            k = (int)(log2(n)); // if n = 14 this gives 3 so it gives the minimum power closest to 13
            jump = 1 << k;      // this gives 8 in case of 14
            n = n - jump;       // we then find whatever the result is then do the same for the result
            counter++;          // for each such iteration we update counter
        }

        cout << counter << endl;
    }
}