#include <iostream>
#include <cstring>
using namespace std;

void moveatend(char *inp, int i, int l)
{
    if (i >= l)
    {
        return;
    }
    char x = inp[i];
    if (x != 'x')
    {
        cout << x;
    }
    moveatend(inp, i + 1, l);
    if (x == 'x')
    {
        cout << x;
    }
    return;
}


int main()
{
    char inp[10001];
    cin >> inp;
    int l = strlen(inp);
    moveatend(inp, 0, l);
}
