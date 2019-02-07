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

void display(Node *head)
{
    Node * p = head;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}

void insertAtBeginning(Node** head, int newData)
{
    Node * newNode = new Node(newData);
    newNode->next = (*head);
    (*head) = newNode;
}

void insertAtEnd(Node** head, int newData)
{
    Node * newNode = new Node(newData);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node * p = (*head);
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
}

void deleteList(Node ** head)
{
    Node * curr = (*head);
    Node * temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    (*head) = NULL;
}

int findOccurences(Node * head, int data)
{
    int occ = 0;
    Node * p = head;
    while(p != NULL)
    {
        if(p->data == key)
            occ++;
        p = p->next;
    }
    return occ;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}