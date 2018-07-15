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

int isLengthEvenOrOdd(struct Node* head)
{
     int count = 0;
     Node * p = head;
     while(p != NULL)
     {
         count++;
         p = p->next;
     }
     return count%2;
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}
