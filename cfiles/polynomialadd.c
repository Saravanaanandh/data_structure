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

Node  *add(Node *poly1,Node *poly2){
    Node *result;
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->exp == poly2->exp){
            insert(&result, poly1->coef+poly2->coef,poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }else if(poly1->exp > poly2->exp){
            insert(&result, poly1->coef,poly1->exp);
            poly1 = poly1->next; 
        }else{
            insert(&result, poly2->coef,poly2->exp);
            poly2 = poly2->next;
        }
    }
    while(poly1 != NULL){
        insert(&result,poly1->coef,poly1->exp);
        poly1 = poly1->next;
    }
    while(poly2 != NULL){
        insert(&result,poly2->coef,poly2->exp);
        poly2 = poly2->next;
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
    Node *result = add(poly1,poly2);
    printf("\n Result:");
    display(result);
}