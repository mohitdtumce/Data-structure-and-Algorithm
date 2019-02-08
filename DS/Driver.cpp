#include <bits/stdc++.h>
// #include "SinglyLinkedList.h"
// #include "DoublyLinkedList.h"
// #include "CircularLinkedList.h"
// #include "ArrayStack.h"
#include "LLStack.h"
using namespace std;

int main()
{
    try
    {
        LLStack<int> S;
        S.Push(1);
        S.Push(2);
        S.Push(3);
        S.Push(4);
        S.Push(5);
        S.Push(6);
        S.Push(7);
        S.Push(8);
        cout << S.Size() << "\n";
        while (!S.Empty())
        {
            cout << S.Top() << " ";
            S.Pop();
        }
    }
    catch (const char *excep)
    {
        cout << excep << '\n';
    }
}