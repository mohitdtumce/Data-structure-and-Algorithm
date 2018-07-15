#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
};

void rotate(struct node **head, int k)
{
    if ((*head) == NULL || (*head)->next == NULL || (k == 0))
        return;
    node * slow = (*head);
    node * fast = (*head);
    for (int i = 1; fast != NULL && i < k; ++i)
        fast = fast->next;
    slow = fast;
    while(fast->next != NULL)
        fast = fast->next;

    fast->next = (*head);
    (*head) = slow->next;
    slow->next = NULL;
}
int main(int argc, char const *argv[])
{
    node * head = NULL;
    return 0;
}