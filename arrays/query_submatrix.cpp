#include <iostream>
using namespace std;
//submatrix query give left top bottom right values
int main()
{
    int n,m,tl1,br1,tl2,br2;
    int sum=0;
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
    cout<<"Enter values for top left:"<<endl;
    cin>>tl1>>tl2;
    cout<<"Enter values for bottom right:"<<endl;
    cin>>br1>>br2;
    cout<<"The query sum is :"<<endl;
    for(int i=tl1;i<=br1;i++)
    {
        for(int j=tl2;j<=br2;j++)
        {
            sum+=a[i][j];
        }
    }
    cout<<sum;
}