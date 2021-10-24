#include <iostream>
using namespace std;

void replacepi(char a[], int i)
{
    //base case
    if (a[i] == '\0' or a[i + 1] == '\0')
    {
        return;
    }

    //look for pi for current location
    if (a[i] == 'p' and a[i + 1] == 'i')
    {
        //shifting and replacement by 3.14
        int j = i + 2;
        //take j to end of array
        while (a[j] != 0)
        {
            j++;
        }
        //shifting elements right to left
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        //replacement and recursuve call for remaining part
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replacepi(a, i + 4);
    }
    else
    {
        //go to next position
        replacepi(a, i + 1);
    }
    return;
}

int main()
{
    char a[1000];
    cin >> a;
    replacepi(a,0);
    cout << a;
    return 0;
}