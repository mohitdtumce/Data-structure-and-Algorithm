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

Node * intersection(Node * a, Node * b)
{
    if (a == NULL || b == NULL)
        return NULL;

    Node * result = NULL;
    if (a->data == b->data)
    {
        result = a;
        result->next =intersection(a->next, b->next);
    }
    else if(a->data < b->data)
    {
        a = a->next;
    }
    else
    {
        b = b->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}