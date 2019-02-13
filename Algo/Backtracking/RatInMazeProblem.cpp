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

int xMoves[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int yMoves[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool IsSafe(vector<vector<bool>> &maze, vector<vector<bool>> &visited,
            int r, int c, const int &Row, const int &Col)
{
    return (r >= 0 && r < Row && c >= 0 && c < Col && maze[r][c] && !visited[r][c]);
}

bool RatInMazeHelper(vector<vector<bool>> &maze, vector<vector<bool>> &visited,
                     int r, int c, const int &Row, const int &Col)
{
    if (r == Row - 1 && c == Col - 1)
    {
        visited[r][c] = true;
        return true;
    }
    else
    {
        if (IsSafe(maze, visited, r, c, Row, Col))
        {
            visited[r][c] = true;
            for (int i = 0; i < 8; i++)
            {
                if (RatInMazeHelper(maze, visited, r + xMoves[i], c + yMoves[i], Row, Col))
                    return true;
            }
            visited[r][c] = false;
        }
        return false;
    }
}

bool RatInMaze(vector<vector<bool>> &maze)
{
    int Row = maze.size();
    int Col = maze[0].size();
    vector<vector<bool>> visited(Row, vector<bool>(Col, false));

    if (RatInMazeHelper(maze, visited, 0, 0, Row, Col))
    {
        PrintGrid(visited);
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<vector<bool>> maze = {{1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {0, 1, 0, 0},
                                 {1, 1, 1, 1}};
    cout << RatInMaze(maze);
    return 0;
}