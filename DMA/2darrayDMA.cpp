#include <iostream>
using namespace std;
int main()
{
    int **arr;
    int r, c;

    cin >> r >> c;

    //create an array of row heads
    arr = new int *[r];

    //create a 2d array
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }

    //to take inputs and print
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}