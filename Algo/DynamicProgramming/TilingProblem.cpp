#include <bits/stdc++.h>
using namespace std;

int TilingWays(int N)
{
    if (N <= 1)
        return 0;
    else if (N == 2 || N == 3)
        return 1;

    int a = 0, b = 1, c;
    for (int i = 3; i <= N; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    cout << TillingWays(9);
}