#include <iostream>
using namespace std;
int main()
{
    int n,m;
    int a[100][100];
    cout<<"Enter the number of rows in array:";
    cin>>m;
    cout<<"Enter the number of colums in array:";
    cin>>n;
    cout<<"Enter the values for array: ";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter a["<<i<<"]"<<"["<<j<<"]";
            cin>>a[i][j];
        }
    }

    cout<<"The wave print is: "<<endl;

    for(int j=0;j<n;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<m;i++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int i=m-1;i>-1;i--)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
}