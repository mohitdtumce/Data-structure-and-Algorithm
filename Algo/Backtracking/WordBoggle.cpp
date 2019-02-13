#include <bits/stdc++.h>
using namespace std;

vector<int> xMoves = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> yMoves = {-1, 0, 1, 1, 1, 0, -1, -1};

bool IsSafe(vector<vector<char>> &grid, vector<vector<bool>> &visited,
            int r, int c, const int &Row, const int &Col, char ch)
{
    return (r >= 0 && r < Row && c >= 0 && c < Col && !visited[r][c] && grid[r][c] == ch);
}

bool WordPresentHelper(vector<vector<char>> &grid, vector<vector<bool>> &visited,
                       const string &str, int start, int end, int r, int c, const int &Row, const int &Col)
{
    if (start > end)
    {
        return true;
    }
    else
    {
        if (IsSafe(grid, visited, r, c, Row, Col, str[start]))
        {
            visited[r][c] = true;
            for (int i = 0; i < 8; i++)
            {
                if (WordPresentHelper(grid, visited, str, start + 1, end,
                                      r + xMoves[i], c + yMoves[i], Row, Col))
                    return true;
            }
            visited[r][c] = false;
        }
        return false;
    }
}

bool WordPresent(vector<vector<char>> &grid, const string &str)
{
    int Row = grid.size();
    int Col = grid[0].size();
    vector<vector<bool>> visited(Row, vector<bool>(Col, false));
    for (int r = 0; r < Row; r++)
    {
        for (int c = 0; c < Col; c++)
        {
            if (WordPresentHelper(grid, visited, str, 0, str.size() - 1, r, c, Row, Col))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};
    vector<vector<char>> grid = {{'G', 'I', 'Z'},
                                 {'U', 'E', 'K'},
                                 {'Q', 'S', 'E'}};

    for (int i = 0; i < dictionary.size(); i++)
    {
        if (WordPresent(grid, dictionary[i]))
            cout << dictionary[i] << " present\n";
        else
            cout << dictionary[i] << " not present\n";
    }
    return 0;
}