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
// This method will change the initial LinkedLists a and b
Node * sortedIntersection(Node * a, Node * b)
{
    if(a == NULL || b == NULL)
        return NULL;
    
    Node * result = NULL;
    if(a->val == b->val)
    {
        result = a;
        result->next = sortedIntersection(a->next, b->next);
    }
    else if (a->val < b->val)
    {
        result = sortedIntersection(a->next, b);
    }
    else
    {
        result = sortedIntersection(a, b->next);
    }
    return result;
}

void intersection(Node **a, Node **b,Node **c)
{
    Node * p = (*a);
    Node * q = (*b);
    (*c) = sortedIntersection(p, q);
}

// This Method will use additional memory to store the intersection.
Node * sortedIntersection(Node * a, Node * b)
{
    if(a == NULL || b == NULL)
        return NULL;
    
    
    if(a->val == b->val)
    {
        Node * result = new Node;
        result->next = NULL;
        result->data = a->data;
        result->next = sortedIntersection(a->next, b->next);
        return result;
    }
    else if (a->val < b->val)
    {
        return sortedIntersection(a->next, b);
    }
    else
    {
        return sortedIntersection(a, b->next);
    }
}

void intersection(Node **a, Node **b,Node **c)
{
    Node * p = (*a);
    Node * q = (*b);
    (*c) = sortedIntersection(p, q);
}
int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}