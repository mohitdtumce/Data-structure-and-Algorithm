#include <bits/stdc++.h>
using namespace std;

void PrintGrid(const vector<vector<bool>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << '\t';
        }
        cout << "\n";
    }
}

bool IsSafe(vector<vector<bool>> &grid, int row, int col, int N)
{
    int r, c;

    r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (grid[r][c])
            return false;
        r--;
        c--;
    }

    r = row, c = col;
    while (r < N && c >= 0)
    {
        if (grid[r][c])
            return false;
        r++;
        c--;
    }

    r = row, c = col;
    while (c >= 0)
    {
        if (grid[r][c])
            return false;
        c--;
    }

    return true;
}

bool NQueenProblemHelper(vector<vector<bool>> &grid, int N, int Col)
{
    if (Col >= N)
    {
        return true;
    }
    else
    {
        for (int Row = 0; Row < N; Row++)
        {
            if (IsSafe(grid, Row, Col, N))
            {
                grid[Row][Col] = true;
                if (NQueenProblemHelper(grid, N, Col + 1))
                    return true;
                grid[Row][Col] = false;
            }
        }
        return false;
    }
}
bool NQueenProblem(int N)
{
    vector<vector<bool>> grid(N, vector<bool>(N, false));

    if (NQueenProblemHelper(grid, N, 0))
    {
        PrintGrid(grid);
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    NQueenProblem(8);
}