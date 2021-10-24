#include <iostream>
using namespace std;
/*You will be given an array containing only 0s, 1s and 2s.
You have to sort the array in linear time that is O(N) where N is the size of the array.*/
 
int main()
{

    int n;
    cin >> n;

    int a[1000],no;
    int zerocounter,twocounter=0;

    for (int i = 0; i < n; i++)
    {
        cin >> no;
        if(no==0)
        {
            zerocounter++;
            a[zerocounter]=0;         
        }
        else if (no==2)
        {
            twocounter++;
            a[n-twocounter]=2;
        }
    }
    for(int i=zerocounter;i<n-twocounter;i++)
    {
        a[i]=1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] <<endl;
    }

    return 0;
}