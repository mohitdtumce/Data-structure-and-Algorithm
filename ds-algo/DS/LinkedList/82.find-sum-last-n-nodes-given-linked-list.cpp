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

int sumOfLastN_Nodes(struct Node* head, int n)
{
	if (head == NULL)
        return 0;
    
    Node * slow = head;
    Node * fast = head;
    int count = 0;
    
    while (count < n && fast != NULL)
    {
        count ++;
        fast = fast->next;
    }

    if(count < n)
        return 0;
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    int sum = 0;
    while ( slow != NULL)
    {
    	sum += slow->data;
    	slow = slow->next;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    Node * head = NULL;
    return 0;
}