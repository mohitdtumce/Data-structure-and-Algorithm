#include <bits/stdc++.h>
using namespace std;

void PrintAllPermutationHelper(string str, int start, int end)
{
    if (start > end)
    {
        cout << str << " ";
        return;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(str[i], str[start]);
            PrintAllPermutationHelper(str, start + 1, end);
            swap(str[i], str[start]);
        }
    }
}
void PrintAllPermutation(string str)
{
    PrintAllPermutationHelper(str, 0, str.size() - 1);
}

void PrintAllPermutationUsingInbuiltFunction(string str)
{
    sort(str.begin(), str.end());
    do
    {
        cout << str << " ";
    } while (next_permutation(str.begin(), str.end()));
}
int main()
{
    PrintAllPermutation("abc");
    cout<<"\n";
    PrintAllPermutationUsingInbuiltFunction("abc");
}