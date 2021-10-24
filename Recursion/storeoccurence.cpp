#include <iostream>
using namespace std;

// store occurences of a key element of an input array in another output array

int storeOccurances(int a[], int i, int n, int key, int output[100], int j)
{
    if (i == n)
    {
        return j;
    }

    if (a[i] == key)
    {
        output[j] = i;
        //increment j to accomodate current occurence
        return storeOccurances(a, i + 1, n, key, output, j + 1);
    }
    //j remains unchanged if no occurence found
    return storeOccurances(a, i + 1, n, key, output, j);
}

int main()
{
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
    int key = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j;
    int output[100];
    cout << endl;
    int count = storeOccurances(arr, 0, n, key, output, 0);
    for (i = 0; i < count; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}