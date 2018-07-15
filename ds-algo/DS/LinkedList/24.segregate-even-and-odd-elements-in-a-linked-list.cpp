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

void insertAtBegining(Node** head, int newData)
{
    Node * newNode = new Node(newData);
    newNode->next = (*head);
    (*head) = newNode;
}

void reverse(Node ** head)
{
    Node * curr = (*head);
    Node * prev = NULL;
    Node * temp;
    while(curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    (*head) = prev;
}

void segregateLL(Node ** head)
{
    // cout<<"Segregating LinkedList\n";
    Node * evenStart = NULL;
    Node * evenEnd = NULL;
    Node * oddStart = NULL;
    Node * oddEnd = NULL;
    Node * curr = *head;

    while(curr != NULL)
    {
        int val = curr->data;
        if(val%2 == 0)
        {
            if(evenStart == NULL)
            {
                evenStart = curr;
                evenEnd = evenStart;
            }
            else
            {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = curr;
                oddEnd = oddStart;
            }
            else
            {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
    }
    if (oddStart == NULL || evenStart == NULL)
        return;
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    *head = evenStart;
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

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    Node * head;
    for (int t = 1; t <= T; ++t)
    {
        head = NULL;
        int n, data;
        cin>>n;
        for (int j = 0; j < n; ++j)
        {
            cin>>data;
            insertAtBegining(&head, data);
        }
        reverse(&head);
        segregateLL(&head);
        display(head);
            deleteList(&head);
    }
    return 0;
}