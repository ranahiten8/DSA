#include<iostream>
using namespace std;
//n k problem

int f(int n,int k)
{   
    //base case
    if(n==0)
    {
        return 1;  // ye ways counter h basically 1 add krta jayega step counter
    }
    if(n<1)
    {
        return 0;
    }

    //recusrsive case
    int ans=0;
    for (int i = 1; i <= k; i++)
    {
        ans+=f(n-i,k);
    }
    return ans;
    
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<f(n,k);
    return 0;
}