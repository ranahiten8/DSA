#include<iostream>
using namespace std;
//We are given two coins of value x and y. We have to find the maximum of value of a XOR b
//where x <= a <= b <= y.
int main()
{
    int x,y;
    cin>>x;
    cin>>y;
    int ans=0;
    for(int i=x;i<=y;i++)
    {
        for(int j=i;j<=y;j++)
        {
            int zor;
            zor=i^j;
            ans=max(zor,ans);
        }
    }
    cout<<ans;
}