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

// Nth Element from the end of the linkedList Brute force method
int getCount(Node * head)
{
    int count = 0;
    Node * p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int nthNodeFromEnd(Node * head, int n)
{
    int count = getCount(head);
    int i = 1;
    Node * p = head;
    while (i < (count - n + 1))
    {
        i++;
        p = p->next;
    }
    return p->data;
}

// nth node from the end of the LinkedList using two pointers
int nthNodeFromEnd2(Node * head, int n)
{
    if (head == NULL)
        return -1;
    
    Node * slow = head;
    Node * fast = head;
    int count = 0;
    
    while (count < n && fast != NULL)
    {
        count ++;
        fast = fast->next;
    }

    if(count < n)
        return -1;
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
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
    cout<<nthNodeFromEnd(head, 11)<<" "<<nthNodeFromEnd(head, 1)<<" "<<nthNodeFromEnd(head, 2)<<"\n";
    cout<<nthNodeFromEnd2(head, 11)<<" "<<nthNodeFromEnd2(head, 1)<<" "<<nthNodeFromEnd2(head, 2)<<"\n";
    cout<<"linkedList Deleted\n";
    deleteList(&head);
    return 0;
}