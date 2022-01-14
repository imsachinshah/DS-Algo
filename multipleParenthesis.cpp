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
    }
}

char pop(struct stack *ptr)
{

    if (isEmpty(ptr))
    {
        cout << "We can't pop, Stack is Underflow " << endl;
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}

int match(char a, char b){
    if(a == '(' && b == ')')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    return 0;
}

int multiParenthesisMatch(char *exp)
{
    stack *sp = new stack();
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char();
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                popped_ch = pop(sp);

                if ( !match(popped_ch, exp[i]))
                {
                    return 0;
                }
        
            }
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

    char *exp = (char*)"[2 + 4 - (4 - 2) + {5 + 8}]";

    if (multiParenthesisMatch(exp))
    {
        cout << "Parenthesis is balanced " << endl;
    }
    else
    {
        cout << "Parenthesis is not balanced " << endl;
    }

    return 0;
}