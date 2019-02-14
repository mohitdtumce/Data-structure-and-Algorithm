#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubtring(string a, string b)
{
    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1, 0));

    int res = 0;
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
            }
            else
            {
                if (a[i] == b[j])
                {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                }
            }

            res = max(res, lcs[i][j]);
        }
    }

    return res;
}

int main()
{
    return 0;
}