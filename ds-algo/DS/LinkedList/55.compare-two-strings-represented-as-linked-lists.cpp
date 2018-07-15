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

int compare(Node * a, Node * b)
{
    if (a == NULL && b == NULL)
        return 0;
    else if (a == NULL)
        return -1;
    else if (b == NULL)
        return 1;
    else
    {
        if (a->data < b->data)
            return -1;
        else if (a->data > b->data)
            return 1;
        else
            return compare(a->next, b->next);
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}