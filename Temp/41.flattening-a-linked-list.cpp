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

Node * helper(Node * a, Node * b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node * result = NULL;
    if (a->data < b->data)
    {
        result = a;
        result->bottom = helper(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = helper(a, b->bottom);
    }
    return (result);
}

Node * flatten(Node *root)
{
    if (root == NULL)
        return NULL;
    return helper(root, flatten(root->next));
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}