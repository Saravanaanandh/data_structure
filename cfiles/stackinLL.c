#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10
struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node arr[MAX];
    int top;
}Stack;


void initialize(Stack *s){
    s->top = -1;
}

bool isFull(Stack *s){
    if(s->top == MAX-1)
        return 1;
    return 0; 
}
bool isEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    return 0; 
}

void push(Stack *s,struct node value){
    if(isFull(s)){
        printf("\n Stack overflow");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
    printf("\n The element is pushed ");
}

struct node pop(Stack *s){
    struct node ele;
    if(isEmpty(s)){
        printf("\n Stack underflow");
        return;
    }
    ele = s->arr[s->top];
    return ele;
}

struct node peek(Stack *s){
    if(isEmpty(s)){
        printf("\n Stack underflow");
        return;
    }
    return s->arr[s->top];
}
