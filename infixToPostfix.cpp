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

char stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int isOperator(char op){
    if (op == '+' || op == '-' || op == '*' || op == '/'){
        return 1;
    }
    return 0;
}

int precedence(char pre){
    if(pre == '*' || pre == '/'){
        return 3;
    }
    else if(pre == '+' || pre == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

char *infixToPostfix(char *infix)
{
    stack *sp = new stack();
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char();
    
    char *postfix = new char();
    int i = 0, j = 0;
    
    while (infix[i] != '\0')
    {
        if(!isOperator(infix[i])){

            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else{
               
                postfix[j] = pop(sp);
                j++;
                
            }
            
        }

        postfix[j] = '\0';
        
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    return postfix;
    
}

int main()
{

    char *infix = (char*)"a+b-c*d/f";


    cout << "Postfix Exp: " << infixToPostfix(infix) << endl;

    return 0;
}