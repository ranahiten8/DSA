#include <bits/stdc++.h>
using namespace std;

int add(int num1, int num2)
{
    return num1 + num2;
}
int sub(int num1, int num2)
{
    return num1 - num2;
}
int multiply(int num1, int num2)
{
    return num1 * num2;
}
int divide(int num1, int num2)
{
    return num1 / num2;
}

int main()
{
    char condition;
    do
    {
        int ans;
        char option;
        cin >> condition;
        if (condition == 'n')
        {
            break;
        }
        int num1, num2;
        cin >> num1 >> option >> num2;
        if (option == '+')
        {
            ans = add(num1, num2);
        }
        else if (option == '-')
        {
            ans = sub(num1, num2);
        }
        else if (option == '/')
        {
            ans = divide(num1, num2);
        }
        else if (option == '*')
        {
            ans = multiply(num1, num2);
        }
        cout << ans << endl;
    } while (condition == 'y');

    return 0;
}