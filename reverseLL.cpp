#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* reverseList(struct Node* head){
    struct Node* temp = NULL, *nextNode = NULL;

    while (head)
    {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}

void traverseList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next;
    }
}


int main()
{

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->data = 2;
    head->next = second;

    second->data = 72;
    second->next = third;

    third->data = 92;
    third->next = fourth;

    fourth->data = 99;
    fourth->next = NULL;

    cout << "Before Reversing: \n";

    traverseList(head);

    head = reverseList(head);

    cout << "\nAfter Reversion: \n";

    traverseList(head);

    return 0;
}





























