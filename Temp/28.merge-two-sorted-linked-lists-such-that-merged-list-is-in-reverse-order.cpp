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
    if (head == NULL || head->next == NULL)
        return head;
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

Node * helper(Node * a, Node * b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node * result = NULL;
    if (a->data < b->data)
    {
        result = a;
        result->next = helper(a->next, b);
    }
    else
    {
        result = b;
        result->next = helper(a, b->next);
    }
    return (result);
}

Node * mergeResult(Node * a, Node * b)
{
    Node * result = helper(a, b);
    return reverse(result);
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}
