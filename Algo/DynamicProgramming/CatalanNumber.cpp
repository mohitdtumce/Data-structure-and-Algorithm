#include <bits/stdc++.h>
using namespace std;

long NthCatalanNumber(int N)
{
    vector<long> catalan(N, 0);
    catalan[0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            catalan[i] += (catalan[j] * catalan[i - j - 1]);
        }
    }
    return catalan[N - 1];
}

int main()
{
    NthCatalanNumber(10);
    return 0;
}