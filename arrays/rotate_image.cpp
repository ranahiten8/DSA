#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    int a[100][100];
    cin>>m;
    cin>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        reverse(a[i],a[i]+n);  //from STL algorithm header file reverses the rows
    }
    //interchange
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                swap(a[i][j],a[j][i]);
            }
        }
    }
    //print
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
