#include <iostream>
using namespace std;

int binary(int n)
{

    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 2;
    }
    return binary(n - 1) + binary(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout<< binary(n);

    return 0;
}