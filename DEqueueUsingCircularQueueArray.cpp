#include <iostream>
#include<cstdlib>
#include<typeinfo>
using namespace std;

// Double Ended Queue Using Circular Queue with Array
struct DEQueue{
    int size;
    int f;
    int r;
    int *arr;

};

int isEmpty(struct DEQueue *q){

    if(q->f == q->r)
        return 1;
    return 0;
}

int isFull(struct DEQueue *q){

    if(((q->r + 1) % q->size) == q->f)
        return 1;
    return 0;
}

int getFront(struct DEQueue *q)
{
    return q->arr[(q->f + 1) % q->size];
}

int getRare(struct DEQueue *q)
{
    return q->arr[q->r ];
}

void enQueueF(struct DEQueue *q, int val){

    if(isFull(q)){
        cout<< "Queue is Full, Can't Enqueue"<< endl;
        return;
    }
    else{
        q->arr[q->f]= val;

        cout << q->arr[q->f] << " enqueed.\n";

        q->f = (q->size - q->f - 1) % q->size;
    }
}

void enQueueR(struct DEQueue *q, int val){

    if(isFull(q))
        cout<< "Queue is Full, Can't Enqueue"<< endl;
    else{
        q->r = (q->r + 1) % q->size;
        q->arr[q->r]= val;

        cout << q->arr[q->r] << " Enqueed.\n";
    }
}

int deQueueF(struct DEQueue *q){

    int a = -1;

    if(isEmpty(q))
        return 0;
    else{
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;

}

int deQueueR(struct DEQueue *q){

    int a = -1;

    if(isEmpty(q))
        return 0;
    else{
        a = q->arr[q->r];
        q->r = q->r - 1;
    }
    return a;

}

int main(){

    DEQueue *q = new DEQueue();

    q->size = 10;
    q->f = 0;
    q->r = 0;
    q->arr = new int();

    enQueueF(q, 10);
    enQueueF(q, 15);
    enQueueF(q, 14);
    enQueueF(q, 1);

    cout<< "The value at Front is: "<< getFront(q) << endl;

    cout<< "The value at Rare is: "<< getRare(q) << endl;

    cout<< "The value dequeued is: "<< deQueueR(q) << endl;

    enQueueF(q, 12);

    cout<< "The value at Front is: "<< getFront(q) << endl;

    cout<< "The value at Rare is: "<< getRare(q) << endl;

    cout<< "The value dequeued is: "<< deQueueF(q) << endl;


    return 0;
}