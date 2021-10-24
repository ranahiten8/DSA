#include <iostream>
#include <algorithm>
using namespace std;
// to find sum of 3 elements in a sorted array that sum to Key
int main()
{

    int key, n;
    int a[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> key;

    //pick one element and do 2 pointer approach for other 2 elements
    for (int k = 0; k < n; k++) 
    {
        int i = k + 1;
        int j = n - 1;
        while (i < j) //2 pointer approach
        {
            int csum = a[i] + a[j] + a[k];
            if (csum < key)
            {
                i++;
            }
            else if (csum > key)
            {
                j--;
            }
            else if (csum == key)
            {
                cout << a[k] << ", " << a[i] << " and " << a[j] << endl;
                i++;
                j--;
            }
        }
    }
}