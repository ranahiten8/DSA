#include <iostream>
using namespace std;

void generatestrings(char *in, char *out, int i, int j)
{
    //base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    //rec case
    //one digit at a time
    int digit = in[i] - '0'; 
    char ch = digit + 'A' - 1; //digit + ascii of A - 1
    out[j] = ch;
    generatestrings(in, out, i + 1, j + 1);

    //two digit at a time
    if (in[i + 1] != '\0')
    {
        int seconddigit = in[i + 1] - '0';
        int no = digit * 10 + seconddigit;
        if (no <= 26)
        {
            ch = no + 'A' - 1;
            out[j] = ch;
            generatestrings(in, out, i + 2, j + 1);
        }
    }
}

int main()
{
    char d[100];
    cin >> d;
    char out[100];
    generatestrings(d, out, 0, 0);
    return 0;
}