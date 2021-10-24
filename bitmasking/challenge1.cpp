#include <iostream>
using namespace std;

int main()
{
    int q, a, b;
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        int count = 0;
        for (int i = b; i >= a; i--)
        {
            int number=i;
            while (i)
            {
                i &= (i - 1);
                count++;
            }
            i=number;           
        }
        cout<<count<<endl;
    }
}