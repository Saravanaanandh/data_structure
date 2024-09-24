#include<stdio.h>

typedef struct{
    int data;
    struct node *next;
}node;
node *top = NULL;
void insert(){
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter node data:");
    scanf("%d",&newnode->data);
    newnode->next = top;
    top = newnode;
}
void delete(){
    int ele;

}
 
void display();

void main()
{
    int choice;
}