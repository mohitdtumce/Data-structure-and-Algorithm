#include <bits/stdc++.h>
using namespace std;

int MaximumSizeSquareSubmatrix(const vector<vector<bool>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    int res = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = matrix[i][j];
            else
            {
                if (matrix[i][j])
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
            res = max(res, dp[i][j]);
        }
    }

    return res;
}
int main()
{
    vector<vector<bool>> matrix = {{0, 1, 1, 0, 1},
                                   {1, 1, 0, 1, 0},
                                   {0, 1, 1, 1, 0},
                                   {1, 1, 1, 1, 0},
                                   {1, 1, 1, 1, 1},
                                   {0, 0, 0, 0, 0}};
    cout<<MaximumSizeSquareSubmatrix(matrix);
    return 0;
}