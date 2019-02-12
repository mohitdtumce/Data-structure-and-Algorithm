#include <bits/stdc++.h>
using namespace std;

// #include "SinglyLinkedList.h"
// #include "DoublyLinkedList.h"
// #include "CircularLinkedList.h"
// #include "ArrayStack.h"
// #include "LLStack.h"
// #include "PriorityQueue.h"
// #include "BinaryTree.h"
// #include "BinarySearchTree.h"
// #include "Trie.h"
// #include "DirectedGraph.h"
#include "UndirectedGraph.h"

int main()
{
    try
    {
        // vector<pair<int, int> > edges = {make_pair(0, 1), make_pair(0, 2), make_pair(2, 3), make_pair(3, 4)};
        UndirectedGraph g1(5);
        g1.AddEdge(1, 0);
        g1.AddEdge(0, 2);
        g1.AddEdge(2, 0);
        g1.AddEdge(0, 3);
        g1.AddEdge(3, 4);
        cout << g1.IsCyclic();

        UndirectedGraph g2(3);
        g2.AddEdge(0, 1);
        g2.AddEdge(1, 2);
        cout<<g2.IsCyclic();
    }
    catch (const char *excep)
    {
        cout << excep << '\n';
    }
}