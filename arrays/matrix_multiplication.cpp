#include <iostream>
using namespace std;

int main()
{   int m1,n1,m2,n2;
    
    cout<<"Input the rows and colums of array 1: "<<endl;
    cin>>m1>>n1;
    cout<<"Input rows and colums of array 2: "<<endl;
    cin>>m2>>n2;
    if(n1!=m2)
    {
        cout<<"Not Possible";
        return 0;
    }
    else
    {
        int a[100][100],b[100][100],c[100][100];

        //array 1 inputs
        cout<<"Enter the array 1 values: "<<endl;
        for(int i=0;i<m1;i++)
        {
            for(int j=0;j<n1;j++)
            {
                cout<<"Enter a["<<i<<"]"<<"["<<j<<"]";
                cin>>a[i][j];
            }
        }
        //array 2 inputs
        cout<<"Enter the array 2 values: "<<endl;
        for(int i=0;i<m2;i++)
        {
            for(int j=0;j<n2;j++)
            {
            cout<<"Enter b["<<i<<"]"<<"["<<j<<"]";
            cin>>a[i][j];
            }
        }
        //multiply
        cout<<"Multiplication of arrays is: ";
   
        for(int i=0;i<m1;i++)
        {
            for(int j=0;i<n2;j++)
            {
                for(int k=0;k<m1;k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                }
                 
            }
        }
        
    
        for(int i=0;i<m1;i++)
        {
        
            for(int j=0;j<n2;j++)
            {
            
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    

}