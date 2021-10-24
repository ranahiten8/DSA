#include <iostream>
using namespace std;

int main()
{
    int m,n,key,a[30][30];
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>key;

    int ans=0;
    
    int i=0;
    int j=n-1;
    while(i<n and j>=0)
    {
        if(key>a[i][j])
        {
            i++;
        }
        else if(key<a[i][j])
        {
            j--;
        }
        else if(key==a[i][j])
        {
            ans=1;
            break;
        }
    }
    cout<<ans;
    return 0;
}