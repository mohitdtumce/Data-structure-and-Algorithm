#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node * next;
};

void display(Node *head)
{
    Node * p = head;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{
	Node * head = NULL;
	return 0;
}