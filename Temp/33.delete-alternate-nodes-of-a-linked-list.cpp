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

void deleteAlt(Node * head)
{
    Node * curr = head;
    Node * nxt = NULL;
    while(curr && curr->next)
    {
        nxt = curr->next;
        curr->next = nxt->next;
        delete nxt;
        curr = curr->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}