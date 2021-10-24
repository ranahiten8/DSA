#include <iostream>
using namespace std;

void bubblesortrecursive(int a[], int j, int n)
{
    //base case
    if (n == 1)
    {
        return;
    }
    if (j == n - 1)
    {
        //single pass of current array has been done
        return bubblesortrecursive(a, 0, n - 1);
    }

    //rec case
    if (a[j] > a[j + 1])
    {
        swap(a[j], a[j + 1]);
    }
    bubblesortrecursive(a, j + 1, n);
    return;
}

int main()
{
    int a[] = {5, 4, 3, 1, 2};
    int n = 5;
    int j = 0;
    bubblesortrecursive(a, j, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    return 0;
}