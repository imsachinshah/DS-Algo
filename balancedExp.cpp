#include <iostream>
#include<cstdlib>
#include<typeinfo>
using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{

    if (ptr->top == -1)
    {
        // cout << "Stack is underflow. " << endl;
        return 1;
    }
    else
    {

        // cout<< "Stack is non empty. "<< endl;
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        // cout << "Stack is Overflow. " << endl;
        return 1;
    }
    else
    {
        // std::cout << "Stack is not Full" << std::endl;
        return 0;
    }
}

void push(struct stack *ptr, char data)
{

    if (isFull(ptr))
    {
        cout << "We can't push, Stack is Overflow" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;

        cout << "Element " << ptr->arr[ptr->top] << " is sucessfully pushed " << endl;
    }
}

void pop(struct stack *ptr)
{

    if (isEmpty(ptr))
    {
        cout << "We can't pop, Stack is Underflow " << endl;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        cout << " Element " << val << "is poped out." << endl;
    }
}

int parenthesisMatch(char *exp)
{
    stack *sp = new stack();
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char();

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }

            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{

    char *exp = "(2 - 3(8 + )9 - 6)))";

    if (parenthesisMatch(exp))
    {
        cout << "Parenthesis is balanced " << endl;
    }
    else
    {
        cout << "Parenthesis is not balanced " << endl;
    }

    return 0;
}