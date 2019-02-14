#include <bits/stdc++.h>
using namespace std;

int RodCuttingProblem(int N, const vector<int> & Prices)
{
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        dp[i] = Prices[i];
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + dp[i - j - 1]);
        }
    }

    return dp[N - 1];
}

int main()
{
}