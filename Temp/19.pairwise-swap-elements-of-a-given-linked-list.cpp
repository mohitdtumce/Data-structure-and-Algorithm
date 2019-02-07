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

void pairWiseSwap(struct node *head)
{
    node * p = head;
    while (p && p->next)
    {
        swap(p->data, p->next->data);
        p = p->next->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}