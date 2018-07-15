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

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}