// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[s..m]
// Second subarray is arr[m+1..e]
void merge(int a[], int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100]; //to store merged values

    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];// a[i] chota h to a[i] dalo temp me aur k++ i++ kro
        }
        else
        {
            temp[k++] = a[j++];// a[j] chota h to a[j] dalo temp me aur k++ j++ kro
        }
    }

    while (i <= mid) //for remaining elements agar mid ke left side wala subarray bada h to
    {
        temp[k++] = a[i++];
    }

    while (j <= e)//for remaining elements agar mid ke right side wala subarray bada h to
    {
        temp[k++] = a[j++];
    }

    for (int i = s; i <= e; i++) //original array me copy krne ke liye temp se
    {
        a[i] = temp[i];
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    //base case
    if (l >= r)
    {
        return; //returns recursively
    }

    //rec case
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, r);
}

// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}


 