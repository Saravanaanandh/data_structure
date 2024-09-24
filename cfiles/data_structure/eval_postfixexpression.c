#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

#define MAX 10

typedef struct
{
    int stckarr[MAX];
    int top;
}Stack;

void initialize(Stack *s) 
{
    s->top = -1;
}

bool isFull(Stack *s)
{
    if(s->top == MAX -1)
        return 1;
    return 0;
}
bool isEmpty(Stack *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

void push(Stack *s,char value)
{
    if(isFull(s))
    {
        printf("\n Stack overflow");
        return;
    }
    s->top++;
    s->stckarr[s->top] = value;
    
}

char pop(Stack *s)
{
    char ele;
    if(isEmpty(s)){
        printf("\n Stack underflow");
        return -1;
    }
    ele = s->stckarr[s->top];
    s->top--;
    return ele;
}

int evaluate(char x,int op1,int op2)
{
    if(x == '+')
        return (op1 + op2);
    if(x == '-')
        return (op1 - op2);
    if(x == '*')
        return (op1 * op2);
    if(x == '/')
        return (op1 / op2);
    if(x == '%')
        return (op1 % op2);  
}

int main()
{
    Stack stack;
    initialize(&stack); 
    char x;
    int op1,op2,val;
    printf("\n Enter a postfix expression:");
    while((x = getchar()) != '\n')
    {
        if(isdigit(x))
        {
            push(&stack,x-48);
        }
        else{
            op2 = pop(&stack);
            op1 = pop(&stack);
            val = evaluate(x,op1,op2);
            push(&stack,val);
        } 
    }
    val = pop(&stack);
    printf("\n The evaluated value of post expression is : %d",val);
    return 0;
}
