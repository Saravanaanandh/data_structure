#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coef;
    int exp;
    struct node *next;
}Node;

void insert(Node **n, int data,int expo){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->coef = data;
    temp->exp = expo;
    temp->next = NULL;

    if(n == NULL){
        *n = temp;
        return;
    }

    Node *current = *n;
    while(current != NULL){
        current = current->next;
    }
    current->next = temp;

    printf("\n Polynomial equation inserted successfully....")
}

void main(){
    Node *poly1;
    insert(&poly1, 5,2);
    insert(&poly1, 1,1);
    insert(&poly1, 6,0);
}
