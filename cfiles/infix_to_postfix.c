#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#define MAX 50

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

char peek(Stack *s){
    if(isEmpty(s)){
        printf("\n Stack underflow");
        return -1;
    }
    return s->stckarr[s->top];
}

int precedence(char ch)
{
    if(ch == '(' || ch == ')')
        return 0;
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/'||ch == '%')
        return 2;
}

int intopostfix(char infix[],char postfix[])
{
    void push(Stack *stack,char token);
    Stack stack;
    char token,x;
    initialize(&stack);
    int i,j=0;
    for(i=0;infix[i] != '\0';i++){
        token = infix[i];
        if(isalnum(token))
        {
            postfix[j] = token;
            j++;  
        }
        else
        {
            
            if(token == '(')
                push(&stack,token);
            else
        
            {
                
                if(token == ')')
                
                {
                    
                    while(x = pop(&stack) != '(')
                    {
                        postfix[j] = x;
                        j++;
                    }
                }
                else
                {
                    
                    while(precedence(token) < precedence(peek(&stack)) && !isEmpty(&stack))
                    {
                        x = pop(&stack);
                        postfix[j] = x;
                        j++;
                    }
                    push(&stack,token);
                }
            }
        }
         
    }
    while(!isEmpty(&stack))
    {
        x = pop(&stack);
        postfix[j] = x;
        j++;
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[30],postfix[30];
    Stack stack;
    initialize(&stack);
    printf("\n Enter an infix expression :");
    scanf("%s",&infix);
    intopostfix(infix,postfix);
    printf("\n Postfix expression is %s",postfix);
    return 0;
}

