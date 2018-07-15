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

// Nth Element of the linkedList Iterative
int findNthElement(Node * head, int n)
{
    if (head == NULL)
        return -1;
    Node * p = head;
    int i = 1;
    while (i < n && p != NULL)
    {
        i ++;
        p = p->next;
    }
    if(p == NULL)
        return -1;
    return p->data;
}

int findNthElementRecursive(Node * head, int n)
{
    if (head == NULL)
        return -1;
    if (n == 1)
        return head->data;
    else
        return findNthElementRecursive(head->next, n-1);
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    display(head);
    cout<<findNthElement(head, 1)<<" "<<findNthElement(head, 11)<<" "<<findNthElement(head, 12)<<"\n";
    cout<<findNthElementRecursive(head, 1)<<" "<<findNthElementRecursive(head, 11)<<" "<<findNthElementRecursive(head, 12)<<"\n";
    cout<<"linkedList Deleted\n";
    deleteList(&head);
    return 0;
}