// #include <iostream>
// #include <stack>
// using namespace std;

// bool isValid(char *s)
// {
//     int open = 0;
//     int close = 0;
//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         if (s[i] == '(')
//         {
//             open++;
//         }
//         else if (s[i] == ')')
//         {
//             close++;
//         }
//         if (close > open)
//         {
//             return false;
//         }
//     }
//     if (open == close)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int main()
// {

//     char s[] = "((((a+b))) + ((c-d+f)))";
//     cout << isValid(s);
//     return 0;
// }

// Another approch Stack based

#include <iostream>
#include <stack>
using namespace std;

bool isValid(char *s)
{
    stack<char> express;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            express.push(ch);
        }
        else if (ch == ')')
        {
            if (express.empty() || express.top() != '(')
            {
                return false;
            }
            express.pop();
        }
    }
    return express.empty();
}

int main()
{

    char s[] = "(()(((a+b))) + ((c-d+f)))";
    cout << isValid(s);

    return 0;
}