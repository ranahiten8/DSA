#include <iostream>
using namespace std;

int indices(int*a,int k,int n,int i)
{
    if(i==n)
    {
        return 0;
    }

    if(a[i]==k)
    {
        cout<<i<<" ";
    }

    indices(a,k,n,i+1);
    return 0;
}

int main()
{
    int a[100],n,m;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    indices(a,m,n,0);
    return 0;
}