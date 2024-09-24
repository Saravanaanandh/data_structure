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

    if(*n == NULL){
        *n = temp;
        return;
    }

    Node *current = *n;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = temp;
}

void display(Node *equ){
    if(equ == NULL){
        printf("0\n");
        return;
    }
    Node *temp = equ;
    while(temp != NULL){
        printf("%dX^%d",temp->coef,temp->exp);
        if(temp->next != NULL){
            printf("+");
        }
        temp = temp->next;
    }

}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coef = p1->coef * p2->coef;
            int exp = p1->exp + p2->exp;
            insert (&result, coef, exp);
        }
    }
    return result;
}

void main(){
    Node *poly1= NULL;
    insert(&poly1, 5,2);
    insert(&poly1, 1,1);
    insert(&poly1, 6,0);
    printf("\n Polynomial equation 1 :\n");
    display(poly1);
    Node *poly2= NULL;
    insert(&poly2, 5,2);
    insert(&poly2, 2,1);
    insert(&poly2, 6,0);
    printf("\n Polynomial equation 2 :\n");
    display(poly2);
    Node *result = multiplyPolynomials(poly1,poly2);
    printf("\n Result:");
    display(result);
}