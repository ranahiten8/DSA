#include <iostream>
using namespace std;

int main()
{
    int n, a[100], csum = 0, msum = 0;

    cout << "Please enter the number of elements in the array ";
    cin >> n;
    cout << "Please enter the elements in the array ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "All sums of subarrays are: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            csum += a[j];
            cout << csum;
            cout << endl;
            if (csum > msum)
            {
                msum = csum;
            }
        }

        csum = 0;
    }
    cout << "Max sum is: " << msum;
    return 0;
}