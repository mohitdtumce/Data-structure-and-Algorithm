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

Node* deleteNode(Node *head,int pos)
{
    if(head == NULL)
        return head;
    
    int k = 1;
    Node * p = head;
    Node * q = NULL;
    
    if (pos == 1)
    {
        head = head->next;
        delete p;
        return head;
    }
    
    while (k < pos && p != NULL)
    {
        k++;
        q = p;
        p = p->next;
    }
    
    if (p != NULL)
    {
        q->next = p->next;
        delete p;
        return head;
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}