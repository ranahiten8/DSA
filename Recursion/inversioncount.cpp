#include <iostream>
using namespace std;
// pairs of elements in array which satisfy a[i]>a[j] when i<j
// example array={5,2,4,6,8}...(5,2),(5,4) etc are such pairs

int merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[1000];
    int cnt = 0; //cross inversion cntr
    while (i <= mid and j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    //fill array if some elements are left in one of the arrays
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    //copy all elements back to array a
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }

    return cnt;
}

int inversion_count(int *a, int s, int e)
{
    //base case
    if (s >= e)
    {
        return 0;
    }

    //merge sort
    int mid = (s + e) / 2;
    int x = inversion_count(a, s, mid);
    int y = inversion_count(a, mid + 1, e);
    int z = merge(a, s, e);
    return x + y + z;
}
int main()
{
    int a[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(a) / sizeof(int);
    cout << inversion_count(a, 0, n - 1);

    return 0;
}