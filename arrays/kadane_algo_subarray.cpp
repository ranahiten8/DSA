#include <iostream>
using namespace std;
//max subarray sum
//no need to sort elements in this method but it wont work if all element of array are
//negative

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

    for (int i = 0; i < n; i++)
    {
        csum += a[i];
        if (csum < 0)
        {
            csum = 0; //main trick
        }
        msum = max(csum, msum);
    }

    cout << "Max sum is: " << msum;
    return 0;
}