#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a : gcd(b,a%b); //recursive calls
}

int main()
{
    int n1,n2;
    cin>>n1;
    cin>>n2;
    int lcm,GCD;
    GCD=gcd(n1,n2);
    lcm=(n1*n2)/GCD; // product of nos = lcm*hcf
    cout<<GCD<<lcm;
    return 0;
}