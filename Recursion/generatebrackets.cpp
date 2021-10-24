#include<iostream>
using namespace std;

void generatebrackets(int n,char*a,int i,int close,int open)
{
    //base case
    if(i==2*n)
    {
        a[i]='\0';
        cout<<a<<endl;
    }
    //rec case
    if(open<n)
    {
        a[i]='(';
        generatebrackets(n,a,i+1,close,open+1);
    }
    if(close<open)
    {
        a[i]=')';
        generatebrackets(n,a,i+1,close+1,open);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    char a[100];
    generatebrackets(n,a,0,0,0);
    return 0;
}