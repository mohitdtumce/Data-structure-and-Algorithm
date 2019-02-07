#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
};

Node * mergeResult(Node * a, Node * b)
{
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    Node * result = NULL;
    if (a->data < b->data)
    {
        result = a;
        result->next = mergeResult(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeResult(a, b->next);
    }
    return (result);
}
int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}
