// In a mathematics class, Teacher ask Alice to find the number of all n digit distinct
// integers which is formed by the two distinct digits ai and bi but there is a rule
// to form n digit integer.

// Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.
#include <iostream>
using namespace std;

void ab(char *output, int n, int *count, int i)
{
    if (i == n)
    {
        output[i] == '\0';
        cout << output << endl;
        (*count)++;
        return;
    }

    output[i] = 'a';
    ab(output, n, count, i + 1);

    if (i==0 or output[i - 1] == 'a')
    {
        output[i] = 'b';
        ab(output, n, count, i + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int n;
        cin >> n;
        char output[30];
        int count = 0;
        ab(output, n, &count, 0);
        cout << "#" << j << " : " << count;
    }
    return 0;
}

// alternate best solution using fibonaci numbers O(n)-->

// #include<iostream>
// using namespace std;
// // long long func(int n)
// // {
// //     if(n==1)
// //         return 2;
// //     if(n==2)
// //         return 3;
// //     return func(n-1)+func(n-2);
// // }
// int main() {
//     int T;
//     cin>>T;
//     long long arr[45];
//     arr[0]=1;
//     arr[1]=2;
//     for(int i=2;i<45;i++)
//         arr[i]=arr[i-1]+arr[i-2];
//     for(int i=1;i<=T;i++)
//     {
//         cout<<"#"<<i<<" : ";
//         int N;
//         cin>>N;
//         //cout<<func(N)<<endl; --> TLE
//         cout<<arr[N]<<endl;
//     }
// 	return 0;
// }