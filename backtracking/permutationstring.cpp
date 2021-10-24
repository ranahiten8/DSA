#include<iostream>
using namespace std;

void permute(char*a,int i)
{
    //base case
    if(a[i]=='\0')
    {
        cout<<a<<",";
        return;
    }

    //rec case
    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[j],a[i]);
        permute(a,i+1);
        //backtracking - to restore original array
        swap(a[j],a[i]);
    }
    return;
}

int main()
{
    char a[100];
    cin>>a;
    permute(a,0);
    cout<<"KHATAM";
    return 0;
}