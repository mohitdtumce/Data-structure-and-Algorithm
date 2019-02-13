#include <bits/stdc++.h>
using namespace std;

string RemoveInvalidParenthesis(string str)
{
    set<int> InvalidIndices;

    stack<int> S;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            S.push(i);
        }
        else if (str[i] == ')')
        {
            if (S.empty())
                InvalidIndices.insert(i);
            else
                S.pop();
        }
    }

    while (!S.empty())
    {
        InvalidIndices.insert(S.top());
        S.pop();
    }

    string res = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (InvalidIndices.find(i) == InvalidIndices.end())
        {
            res += str[i];
        }
    }
    return res;
}
int main()
{
    cout << RemoveInvalidParenthesis("(v)()()");
    return 0;
}