#include<iostream>
using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generatenames(char*in,char*out,int i,int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    //rec case
    
    int digit= in[i]-'0';
    //special case
    if(digit==1 or digit==0)
    {
        generatenames(in,out,i+1,j);//ye next i pe lejayegaa aur kuch kaam nhi iska
    }
    //general case
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        out[j]=keypad[digit][k];
        //fill remaining part
        generatenames(in,out,i+1,j+1);
    }


}

int main()
{
    char in[100];
    cin>>in;
 
    char out[100];
    generatenames(in,out,0,0);  
    return 0;
}