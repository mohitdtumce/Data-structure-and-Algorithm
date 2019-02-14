#include <bits/stdc++.h>
using namespace std;

bool SubsetSumProblem(const vector<int> & Coins, int Sum)
{
    int Count = Coins.size();
    vector<vector<bool>> dp(Count + 1, vector<bool>(Sum + 1, false));

    for (int i = 0; i <= Count; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= Count; i++)
    {
        for (int s = 0; s <= Sum; s++)
        {
            if (Coins[i - 1] > s)
            {
                dp[i][s] = dp[i - 1][s];
            }
            else
            {
                dp[i][s] = dp[i - 1][s] || dp[i - 1][s - Coins[i - 1]];
            }
        }
    }

    return dp[Count][Sum];
}
int main()
{
    vector<int> Coins = {3, 34, 4, 12, 5, 2}; 
    int Sum = 10;
    cout<<SubsetSumProblem(Coins, Sum);
}