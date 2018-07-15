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

node * reverseInGroups(node * head, int k)
{
    if(head == NULL || head->next == NULL || k == 1)
        return head;

    node * curr = head;
    node * prev = NULL;
    node * temp;
    int count = 0;
    while(count < k &&  curr != NULL)
    {
        count++;
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    if (curr != NULL)
        head->next = reverseInGroups(curr, k);

    return prev;
}

int main(int argc, char const *argv[])
{
    node * head = NULL;
    return 0;
}