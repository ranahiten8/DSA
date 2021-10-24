#include <iostream>
using namespace std;

// O(1) complexity algorithm brian kernighan algo
int main()
{
    int n;
    cin >> n;
    int no;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        int count = 0;
        while (no)
        {
            no &= (no - 1);
            count++;
        }
        cout<<"setbits are "<<count<<endl;
    }
}