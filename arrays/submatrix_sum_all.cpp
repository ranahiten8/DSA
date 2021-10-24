#include <iostream>
using namespace std;
//sum of all submatrices of given matrix O(n^2) complexity
int main()
{
    int n,m;
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

    cout<<"Sum of all submatrices is: "<<endl;
    //contribution of 1 element
    for(int i=0; i<m;i++)
    {
        for(int j=0; j<n;j++)
        {
            sum+=a[i][j]*(i+1)*(j+1)*(m-i)*(n-j);
        }
    }
    cout<<sum;
}

