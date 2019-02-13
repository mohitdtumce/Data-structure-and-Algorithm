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

// vector<int> xMoves = {-1, -1, -1, 0, 1, 1, 1, 0};
// vector<int> yMoves = {-1, 0, 1, 1, 1, 0, -1, -1};

vector<int> xMoves = {-1, 0, 1, 0};
vector<int> yMoves = {0, 1, 0, -1};

bool IsSafe(vector<vector<bool>> &maze, vector<vector<bool>> &visited,
            int r, int c, const int &Row, const int &Col)
{
    return (r >= 0 && r < Row && c >= 0 && c < Col && maze[r][c] && !visited[r][c]);
}

int RatInMazeHelper(vector<vector<bool>> &maze, vector<vector<bool>> &visited,
                    int r, int c, const int &Row, const int &Col, int &count)
{
    if (r == Row - 1 && c == Col - 1)
    {
        count++;
    }
    else
    {
        if (IsSafe(maze, visited, r, c, Row, Col))
        {
            visited[r][c] = true;
            for (int i = 0; i < 4; i++)
            {
                RatInMazeHelper(maze, visited, r + xMoves[i], c + yMoves[i], Row, Col, count);
            }
            visited[r][c] = false;
        }
    }
}

int RatInMaze(vector<vector<bool>> &maze)
{
    int Row = maze.size();
    int Col = maze[0].size();
    vector<vector<bool>> visited(Row, vector<bool>(Col, false));

    int count = 0;
    RatInMazeHelper(maze, visited, 0, 0, Row, Col, count);
    return count;
}

int main()
{
    vector<vector<bool>> maze = {{1, 1, 1, 1},
                                 {1, 1, 0, 1},
                                 {0, 1, 0, 1},
                                 {1, 1, 1, 1}};
    cout << RatInMaze(maze);
    return 0;
}