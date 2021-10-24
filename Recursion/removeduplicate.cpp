#include <iostream>
using namespace std;

void naya(char *a, int i)
{
    if (a[i + 1] == '\0' or a[i] == '\0')
    {
        return;
    }

    if (a[i] == a[i + 1] and a[i] != '\0')
    {
        int j = i;
        while (a[j] != '\0')
        {
            a[j] = a[j + 1];
            j++;
        }
        naya(a, i);
    }
    else
    {
        naya(a, i + 1);
    }
    return;
}

int main()
{
    char a[1000];
    cin >> a;
    naya(a, 0);
    cout << a;
    return 0;
}