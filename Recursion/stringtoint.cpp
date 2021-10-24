#include <iostream>
#include <cstring>
using namespace std;

int strtoint(char *a, int n)
{
    if (n == 0)
    {
        return 0;
    }

    int digit = a[n - 1] - '0';
    int smallans = strtoint(a, n - 1); 

    return smallans * 10 + digit;
}

int main()
{
    char a[10];
    cin >> a;
    int n = strlen(a);
    cout << strtoint(a, n);
    return 0;
}