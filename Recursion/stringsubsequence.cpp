#include<iostream>
using namespace std;
void printsubsequence(char*input,char*output,int i,int j)
{
    //base case
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    //rec case
    //include current char
    output[j]=input[i];
    printsubsequence(input,output,i+1,j+1);

    //exclude current char
    printsubsequence(input,output,i+1,j); //j ko move nhi krege to apne aap he exclude 
                                          //hojayega
    return;
}

int main()
{
    char input[]="abcd";
    char output[10];
    printsubsequence(input,output,0,0);
    return 0;
}

// alternate code--->

// #include<iostream>
// #include<stack>
// #include<string>
// using namespace std;


// static int count = 0;
// stack <string> s;
// void subsequencesRecur(char*in,char*out,int i,int j)
// {
// 	if (in[i]=='\0')
// 	{
// 		out[j] = '\0';
// 		s.push(out);
// 		count++;
// 		return;
// 	}
// 	out[j] = in[i];
// 	subsequencesRecur(in,out,i+1,j+1);
// 	subsequencesRecur(in,out,i+1,j);
// }

// int main()
// {
// 	char in[100];
// 	cin>>in;
// 	char out[100];
// 	subsequencesRecur(in,out,0,0);
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
// 	cout<<endl<<count;
// 	return 0;
// }