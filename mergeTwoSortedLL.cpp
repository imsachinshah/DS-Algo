#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node *mergeTwoSortedLL(struct Node* head1, struct Node* head2){
    
    Node *head3 = new Node();

    struct Node* temp;

    head3 = new Node;
    head3->next = NULL; 
    temp = head3;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else
        { 
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
        
    }

    if(head1 != NULL){
        temp->next = head1;
    }
    else
    {
        temp->next = head2;
    }
    
    temp = head3->next;
    free(head3);
    
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

    Node *head1 = new Node();
    Node *second1 = new Node();
    Node *third1 = new Node();
    Node *fourth1 = new Node();
    Node *fifth1 = new Node();


    head1->data = 5;
    head1->next = second1;

    second1->data = 9;
    second1->next = third1;

    third1->data = 12;
    third1->next = fourth1;

    fourth1->data = 15;
    fourth1->next = fifth1;

    fifth1->data = 20;
    fifth1->next = NULL;

    Node *head2 = new Node();
    Node *second2 = new Node();
    Node *third2 = new Node();
    Node *fourth2 = new Node();

    head1->data = 2;
    head1->next = second2;

    second2->data = 6;
    second2->next = third2;

    third2->data = 10;
    third2->next = fourth2;

    fourth2->data = 11;
    fourth2->next = NULL;

   // cout << "List Details: \n";

    //traverseList(head);

    struct Node *head = mergeTwoSortedLL(head1, head2);

    cout << "\nAfter Printing Middle Node\n";

    traverseList(head);

    return 0;
}