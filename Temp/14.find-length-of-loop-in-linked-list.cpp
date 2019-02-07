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

int lengthOfLoop(Node * head)
{
    bool isLoop = false;
    if (head == NULL)
        return 0;
    Node * p = head;
    Node * q = head;
    while (p != NULL && p->next != NULL)
    {
        p = p->next->next;
        q = q->next;
        if (p == q)
            isLoop = true;
    }
    if (isLoop)
    {
        int count = 0;
        q = head;
        while(q != p)
        {
            count++;
            q = q->next;
            p = p->next;
        }
        return count;
    }
    else
        return 0;
}

void removeTheLoop(Node * head)
{
    bool isLoop = false;
    if (head == NULL)
        return;
    Node * p = head;
    Node * q = head;
    while (p != NULL && p->next != NULL)
    {
        p = p->next;
        p = p->next;
        q = q->next;
        if (p == q)
        {
            isLoop = true;
            break;
        }
    }
    if (isLoop)
    {
        q = head;
        while(q != p)
        {
            q = q->next;
            p = p->next;
        }
        p->next = NULL;
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}