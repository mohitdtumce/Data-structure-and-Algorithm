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


bool isPalindromeHelper(Node ** left, Node * right)
{
    if (right == NULL)
        return true;
    bool isp = isPalindromeHelper(left, right->next);
    if (isp == false)
        return false;
    bool isp1 = ((*left)->data == right->data);
    (*left) = (*left)->next;
    return isp1;
}

bool isPalindrome(Node* head)
{
    return isPalindromeHelper(&head, head);
}

int main(int argc, char const *argv[])
{
    return 0;
}