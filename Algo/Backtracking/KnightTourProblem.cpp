#include <bits/stdc++.h>
using namespace std;

int xMoves[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int yMoves[] = {1, 2, 2, 1, -1, -2, -2, -1};

#define N 8
#define MAX_MOVES 64

void PrintGrid(const vector<vector<int>> &grid)
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
bool IsSafe(vector<vector<int>> &grid, int row, int col)
{
    return (row >= 0 && row < N && col >= 0 && col < N && grid[row][col] == 0);
}

bool KnightTourProblemHelper(int n, vector<vector<int>> &grid, int row, int col)
{
    if (n > MAX_MOVES)
    {
        return true;
    }
    else
    {
        if (IsSafe(grid, row, col))
        {
            grid[row][col] = n;
            for (int i = 0; i < 8; i++)
            {
                if (KnightTourProblemHelper(n + 1, grid, row + xMoves[i], col + yMoves[i]))
                    return true;
            }
            grid[row][col] = 0;
        }
        return false;
    }
}

bool KnightTourProblem()
{
    vector<vector<int>> grid(N, vector<int>(N, 0));
    if (KnightTourProblemHelper(1, grid, 0, 0))
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
    cout << KnightTourProblem();
    return 0;
}