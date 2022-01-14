#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}

void traverseDLL(struct Node* head){
    struct Node *p = head;
    while(p->next != NULL){
        cout<< "Element is: "<< p->data << endl;
        p->next =  
    }
}


int main() {

    Node n1 = new Node();
    Node n2 = new Node();
    Node n3 = new Node();
    Node n4 = new Node();

    struct Node *head;

    n1.data = 5;
    n2.data = 9;
    n3.data = 2;
    n4.data = 10;

    n1.prev = NULL;
    n1.next = n2;

    n2.prev = n1;
    n2.next = n3;

    n3.prev = n2;
    n3.next = n4;

    n4.prev = n3;
    n4.next = NULL;

    return 0;
}