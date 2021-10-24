#include <iostream>
using namespace std;
bool rat(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
    if (i == m and j == n)
    {
        soln[m][n] = 1;
        //print the path
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    //rat should be inside grid
    if (i > m or j > n)
    {
        return false;
    }

    if (maze[i][j] == 'X')
    {
        return false;
    }

    //assume solution exists through cell
    soln[i][j] = 1;
    bool rightsuccess = rat(maze, soln, i, j + 1, m, n);
    bool downsuccess = rat(maze, soln, i + 1, j, m, n);

    //backtracking condition
    soln[i][j] = 0;

    if (rightsuccess or downsuccess)
    {
        return true;
    }
    return false;
}

int main()
{
    char maze[10][10] = {"0000",
                         "00X0",
                         "000X",
                         "0X00"};
    int soln[10][10] = {0};
    int m = 4, n = 4;
    bool ans = rat(maze, soln, 0, 0, m - 1, n - 1);
    if (ans == false)
    {
        cout << "path dont exist";
    }
    return 0;
}