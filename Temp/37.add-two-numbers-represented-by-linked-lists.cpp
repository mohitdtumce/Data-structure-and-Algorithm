#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        // Node(int data) 
        // {
        //     this->data = data;
        //     this->next = NULL;
        // }
};
Node * createNode(int data)
{
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node * addTwoLists(Node * a, Node * b)
{
    Node * result = NULL;
    Node * tail = NULL;
    Node * temp;
    int carry = 0, sum = 0;
    while (a != NULL || b != NULL)
    {
        sum = carry + ((a != NULL)?(a->data):0) + ((b != NULL)?(b->data):0);
        carry = sum/10;
        sum %= 10;
        temp = createNode(sum);
        if (result == NULL)
        {
            result = temp;
            tail = result;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }

        if (a)
            a = a->next;
        if (b)
            b = b->next;
    }

    if (carry > 0)
    {
        temp->next = createNode(carry);
    }
    return result;
}
int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}