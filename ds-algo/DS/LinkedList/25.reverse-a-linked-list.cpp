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

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}