#include <iostream>
using namespace std;
int main()
{
    int bx,by,tx,ty;
    int sum=0;
    int a[3][3]={1,1,1,1,1,1,1,1,1};
    int b[3][3];
    cout<<"Enter values for top left:"<<endl;
    cin>>tx>>ty;
    cout<<"Enter values for bottom right:"<<endl;
    cin>>bx>>by;
    cout<<"The query sum is :"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum+=a[i][j];
            b[i][j]=sum;
        }
        sum=0;
    }
    for(int j=0;j<3;j++)
    {
        for(int i=0;i<3;i++)
        {
            sum+=b[i][j];
            b[i][j]=sum;
        }
        sum=0;
    }
   

}