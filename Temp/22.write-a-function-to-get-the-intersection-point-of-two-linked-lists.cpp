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

int getCount(Node * head)
{
    int count = 0;
    Node * p = head;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int helper(Node * a, Node * b, int d)
{
    for(int i = 0; i < d; i++)
    {
        a = a->next;
    }
    
    while(a && b)
    {
        if(a == b)
        {
            return a->data;
        }
        a = a->next;
        b = b->next;
    }
    return -1;
}

int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL)
        return -1;
    int s1 = getCount(head1);
    int s2 = getCount(head2);
    int d;
    Node * p = head1;
    Node * q = head2;
    if (s1 >= s2)
    {
        return helper(p, q, s1 - s2);   
    }
    else
    {
        return helper(q, p, s2 - s1); 
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}