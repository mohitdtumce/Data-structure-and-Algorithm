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

bool areIdentical(Node * a, Node * b)
{
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;

    return ((a->data == b->data) && areIdentical(a->next, b->next));   
}
int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}