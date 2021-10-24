#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
string searchIn[] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh",
                     "divyam", "vidhi", "sparsh", "akku"};

string strings[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, int i, int j, char out[], char out1[])
{
    if (s[i] == '\0')
    {
        out[j] = '\0';
        for (int p = 0; p < 11; p++)
        {
            int found = searchIn[p].find(out); //check if substring is present or not
            if (found != -1)
            {
                cout << searchIn[p] << endl;
            }
        }
        return;
    }
    int digit = s[i] - '0';

    //special case
    if (digit == 0 || digit == 1)
    {
        keypad(s, i + 1, j, out, out1);
    }

    for (int k = 0; strings[digit][k] != '\0'; k++)
    {
        out[j] = strings[digit][k];
        keypad(s, i + 1, j + 1, out, out1);
    }
}

int main()
{
    string s;
    char out[100];
    char out1[100];
    cin >> s;

    keypad(s, 0, 0, out, out1);
}