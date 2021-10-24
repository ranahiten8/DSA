#include <iostream>
#include <cstring>
using namespace std;
//read n followed by n strings and print largest string and its length

int main()
{
    char max[100];
    char curr[100];
    int high,cur=0;
    int n;
    cout<<"Input the number of strings:"<<endl;
    cin>>n;
    cin.get();
    cout<<"Input the strings:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin.getline(curr,100);
        cur=strlen(curr);
        if(cur>high)
        {
            high=cur;
            strcpy(max,curr);
        }

    }
    cout<<"max length is:"<<high<<endl;
    cout<<"string is :"<<max;

    return 0;

}