#include <bits/stdc++.h>
using namespace std;

int MaximumSumIncreasingSubsequence(const vector<int> &vec)
{
    vector<int> msis(vec.size());
    int maxSum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        msis[i] = vec[i];
        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i] && msis[j] + vec[i] > msis[i])
            {
                msis[i] = max(msis[i], msis[j] + vec[i]);
            }
        }
        maxSum = max(maxSum, msis[i]);
    }
    return maxSum;
}

int main()
{
    vector<int> vec = {1, 101, 2, 3, 100, 4, 5};
    cout<<MaximumSumIncreasingSubsequence(vec);
    return 0;
}