#include <bits/stdc++.h>
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

Node * reverse(Node * head, int k)
{
    if (head == NULL || head->next == NULL || k == 1)
        return head;

    stack<Node*> myStack;
    Node * curr = head;
    Node * prev = NULL;
    while(curr != NULL)
    {
        int count = 0;
        
        while(count < k && curr != NULL)
        {
            count++;
            myStack.push(curr);
            curr = curr->next;
        }
        while(myStack.empty() == false)
        {
            if(prev == NULL)
            {
                prev = myStack.top();
                head = prev;
                myStack.pop();
            }
            else
            {
                prev->next = myStack.top();
                prev = prev->next;
                myStack.pop();
            }
        }
    }
    prev->next = NULL;
    return head;
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}