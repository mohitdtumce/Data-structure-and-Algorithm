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

Node * reverse(Node * head)
{
    Node * curr = head;
    Node * prev = NULL;
    Node * temp;
    while(curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node * compute(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    head = reverse(head);
    Node * p = head;
    Node * q = NULL;
    while (p->next != NULL)
    {
        if(p->data > p->next->data)
        {
            q = p->next;
            p->next = q->next;
            delete q;
        }
        else
        {
            p = p->next;
        }
    }
    return reverse(head);
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}