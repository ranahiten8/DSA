#include<iostream>
using namespace std;
/*We are given an array containg n numbers.
All the numbers are present thrice except for one number which is only present once.
Find the unique number. Only use - bitwise operators, and no extra space.*/

int main()
{
    int n,no;
    int sum[64]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        int j=0;   
        while(no>0)
        {
            int lastbit=no&1;
            sum[j]+=lastbit;
            no=no>>1;
            j++;
        }
    }

    int p=1;
    int ans=0;
    for(int i=0;i<64;i++)
    {
        sum[i]%=3;
        ans+=sum[i]*p;
        p=p<<1;
    }

    cout<<ans;
}