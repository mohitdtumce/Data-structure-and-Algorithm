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

void printReverse(Node * head)
{
    if (head == NULL)
        return;
    printReverse(head->next);
    cout<<head->data<<" ";
    cout<<"\n";
}
int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}