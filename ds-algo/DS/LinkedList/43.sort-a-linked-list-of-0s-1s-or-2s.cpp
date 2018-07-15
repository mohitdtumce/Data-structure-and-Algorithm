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

void sortList(Node * head)
{
    int arr[3] = {};
    Node * p = head;
    while (p != NULL)
    {
        arr[p->data%3]++;
        p = p->next;
    }
    p = head;
    int index = 0;
    while (p != NULL)
    {
        if (arr[index] > 0)
        {
            p->data = index;
            arr[index]--;
            p = p->next;
        }
        else
        {
            index++;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}