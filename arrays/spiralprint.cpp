#include <iostream>
using namespace std;
//spiral print of 2d array anti clockwise
//Go for first column-> last row ->last column-> first row and then do the same traversal
//for the remaining matrix .

int main()
{
    int a[20][20], m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int sr, sc = 0;
    int er = m - 1;
    int ec = n - 1;

    while (sc <= ec and sr <= er)
    {
        for (int i = sr; i <= er; i++)
        {
            cout << a[i][sc] << ", ";
        }
        sc++;
        for (int i = sc; i <= ec; i++)
        {
            cout << a[er][i] << ", ";
        }
        er--;
        if (er > sr)
        {
            for (int i = er; i >= sr; i--)
            {
                cout << a[i][ec] << ", ";
            }
            ec--;
        }

        if (ec > sc)
        {
            for (int i = ec; i >= sc; i--)
            {
                cout << a[sr][i] << ", ";
            }
            sr++;
        }
    }
    cout << "END";
}