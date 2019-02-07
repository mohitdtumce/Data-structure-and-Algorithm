#include <bits/stdc++.h>
// #include "SinglyLinkedList.h"
// #include "DoublyLinkedList.h"
#include "CircularLinkedList.h"

using namespace std;

int main()
{
    CircularLinkedList<int> cll;
    try
    {
        cll.PushFront(2);
        cll.PrintList();
        cll.PushFront(1);
        cll.PrintList();
        cll.Insert(5, 3);
        cll.Insert(3, 3);
        cll.Insert(4, 4);
        cll.PrintList();
        cll.PopFront();
        cll.PrintList();
        cll.PopBack();
        cll.PrintList();
        cll.PopFront();
        cll.PrintList();
        cll.PopBack();
        cll.PrintList();
        cll.PopFront();
        cll.PrintList();
        cll.PopBack();
        cll.PrintList();
    }
    catch (const char *e)
    {
        cout << e << '\n';
    }
    catch (...)
    {
        cout << "Unknown Exception";
    }
}