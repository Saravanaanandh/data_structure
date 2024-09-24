#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};
struct node *head,*temp,*newnode;

void nodecreation(){
    newnode = (struct node *)malloc(sizeof(struct node)); 
    printf("\n Enter node data:");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
}
void display(){
    temp = head;
    printf("\n The singly linked list is :");
    while(temp != NULL){
        printf("%d \t",temp->data);
        temp = temp->next;
    }
}
void create(){
    int i;
    head = NULL;
    do{ 
    nodecreation();
    if(head == NULL){
        head = temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    printf("\n Do you continue to add extra node:");
    scanf("%d",&i);
    }while(i == 1);
    display();
}



void insertbeg(){
    temp = head;
    nodecreation();
    head = newnode;
    head->next = temp;
    display();
}
void insertend(){
    temp = head;
    nodecreation();
    while(temp->next != NULL){
        temp = temp->next;
    } 
    temp->next = newnode;
    display();
}
void insertpos(){
    int i = 1,pos;
    printf("\n Enter a position to insert:");
    scanf("%d",&pos);
    temp = head;
    nodecreation();
    while(i < pos-1 ){										//  temp = 200, head = 100 => 10 | 200 => 20|300 => 30 | NULL   <=100|200
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    display();
}

void deletebeg(){
    int ele;
    temp = head;
    ele = head->data;
    head = head->next;
    free(temp);
    printf("\n The element %d is deleted...",ele);
}
void deleteend(){
    int ele;
    struct node *prevnode;
    temp = head;
    while(temp->next != NULL){
        prevnode = temp;
        temp = temp->next;
    }
    ele = temp->data;
    prevnode->next = NULL;
    free(temp);
    printf("\n The element %d is deleted...",ele);
}

void deleteatpos(){
    int i = 1,pos,ele;
    struct node *prevnode;
    printf("\n Enter a position to delete:");
    scanf("%d",&pos);
    temp = head;
    while( i < pos){
        prevnode = temp;
        temp = temp->next;
        i++;
    }
    ele = temp->data;
    prevnode->next = temp->next;
    free(temp);
    printf("\n The element %d is deleted...",ele);
}

void find(){
    int i = 1,ele,flag =0;
    printf("\n Enter an element to search:");
    scanf("%d",&ele);
    temp = head;
    while(temp != NULL ){
        if(temp->data == ele){
            flag = 1;
            printf("\n The element is founded at %d position",i);
        }
        temp = temp->next;
        i++;
    }
    if(flag == 0){
        printf("\n The element is not found.");
    }
}

void main()
{
    int choice;
    printf("\n Main Menu : \n 1.Create \n 2.Display \n 3.InsertAtBeginning \n 4.InsertAtEnd  \n 5.InsertAtPosition  \n 6.DeleteFromBeginning \n 7.DeleteFromEnd  \n 8.DeleteAtPosition  \n 9.FindElement \n 0.Exit \n ");
    do{
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create();
                break;
            
            case 2:
                display();
                break;
            
            case 3:
                insertbeg();
                break;
            
            case 4:
                insertend();
                break;
            
            case 5:
                insertpos();
                break;
            
            case 6:
                deletebeg();
                break;
            
            case 7:
                deleteend();
                break;
            
            case 8:
                deleteatpos();
                break;
            
            case 9:
                find();
                break;
            
            case 0:
                exit(0);
                break;
            
            default:
                printf("\n Enter the correct choice"); 
        }
    }while(1);
}
