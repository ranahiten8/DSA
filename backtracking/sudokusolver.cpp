#include <iostream>
#include <cmath>
using namespace std;

bool possible(int a[][9], int i, int j, int n, int number)
{
    for (int x = 0; x < n; x++)
    {
        //row and col check
        if (a[x][j] == number or a[i][x] == number)
        {
            return false;
        }
    }

    //box check
    int rn = sqrt(n);
    int sx = (i / rn) * rn; // to know position of start of box
    int sy = (j / rn) * rn;

    for (int x = sx; x < sx + rn; x++)
    {
        for (int y = sy; y < sy + rn; y++)
        {
            if (a[x][y] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int a[][9], int i, int j, int n)
{
    //base case
    if (i == n)
    {
        //print
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    //case row end
    if (j == n)
    {
        return solve(a, i + 1, 0, n);
    }
    //skip pre filled cells
    if (a[i][j] != 0)
    {
        return solve(a, i, j + 1, n);
    }

    //rec case
    //fill the current cell with possible options
    for (int number = 1; number <= n; number++)
    {
        if (possible(a, i, j, n, number))
        {
            //assume
            a[i][j] = number;

            bool couldwesolve = solve(a, i, j + 1, n);
            if (couldwesolve == true)
            {
                return true;
            }
        }
    }
    //backtrack here
    a[i][j] = 0;
    return false;
}

int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solve(grid, 0, 0, 9);
    return 0;
}