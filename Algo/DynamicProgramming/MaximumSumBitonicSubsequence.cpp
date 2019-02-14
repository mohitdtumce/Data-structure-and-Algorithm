#include <bits/stdc++.h>
using namespace std;

int MaximumSumBitonicSubsequence(const vector<int> &vec)
{
    int len = vec.size();
    vector<int> msis(len), msds(len);

    for (int i = 0; i < len; i++)
    {
        msis[i] = vec[i];
        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i])
            {
                msis[i] = max(msis[i], msis[j] + vec[i]);
            }
        }
    }

    for (int i = len - 1; i >= 0; i--)
    {
        msds[i] = vec[i];
        for (int j = len - 1; j > i; j--)
        {
            if (vec[j] < vec[i])
            {
                msds[i] = max(msds[i], msds[j] + vec[i]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < len; i++)
    {
        res = max(res, msis[i] + msds[i] - vec[i]);
    }
    return res;
}
int main()
{
    vector<int> vec = {1, 15, 51, 45, 33, 100, 12, 18, 9};
    cout << MaximumSumBitonicSubsequence(vec);
    return 0;
}