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

void removeDuplicate(Node * head)
{
    Node * curr = head;
    Node * temp = NULL;
    while(curr->next)
    {
        if (curr->data == curr->next->data)
        {
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}