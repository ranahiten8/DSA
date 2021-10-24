#include <iostream>
using namespace std;
// to find sum of pair in a sorted array that sum to K

int main()
{

    int k, n;
    int a[100];
    cout << "Enter number of element in array";
    cin >> n;
    cout << "Enter the values for array in sorted order";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the key sum to find";
    cin >> k;
    cout << "The number pairs are: ";
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int csum = a[i] + a[j];
        if (csum < k)
        {
            i++;
        }
        else if (csum > k)
        {
            j--;
        }
        else if (csum = k)
        {
            cout << "The pairs are: " << a[i] << " " << a[j];
            i++;
            j--;
        }
    }
}