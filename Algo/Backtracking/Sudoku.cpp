#include <bits/stdc++.h>
using namespace std;

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

bool FindUnassignedPositions(vector<vector<int>> &Sudoku, int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (Sudoku[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool IsSafe(const vector<vector<int>> &Sudoku, int row, int col, int num)
{
    int r, c;

    r = 0;
    while (r < 9)
    {
        if (Sudoku[r][col] == num)
            return false;
        r++;
    }

    c = 0;
    while (c < 9)
    {
        if (Sudoku[row][c] == num)
            return false;
        c++;
    }

    r = row - (row % 3), c = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Sudoku[r + i][c + j] == num)
                return false;
        }
    }

    return true;
}

bool SudokuSolver(vector<vector<int>> &Sudoku)
{
    int row, col;
    if (!FindUnassignedPositions(Sudoku, row, col))
    {
        PrintGrid(Sudoku);
        return true;
    }
    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (IsSafe(Sudoku, row, col, num))
            {
                Sudoku[row][col] = num;
                if (SudokuSolver(Sudoku))
                    return true;
                Sudoku[row][col] = 0;
            }
        }
        return false;
    }
}

int main()
{
    vector<vector<int>> Sudoku = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                  {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                  {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                  {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                  {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                  {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                  {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    cout << SudokuSolver(Sudoku);
    return 0;
}