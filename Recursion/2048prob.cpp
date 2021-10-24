#include <iostream>
using namespace std;
//ques is input number and print its spelling

char a[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void digit(int n)
{
    if (n == 0)
    {
        return;
    }
    digit(n / 10);
    int p = n % 10;
    cout << a[p] << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    digit(n);
    return 0;
}