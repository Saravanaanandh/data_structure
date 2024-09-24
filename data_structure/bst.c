#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

struct node * newnode(int x){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;
    return newnode;
}

struct node*insert(struct node * root, int x){
    if(root == NULL)
        return newnode(x);
    if(x > root->data)
        root->rightchild = insert(root->rightchild, x);
    else
        root->leftchild = insert(root->leftchild,x);
    return root;
}

struct node * search(struct node * root, int x){
    if(root == NULL || root->data == x)  
        return root;
    if(x > root->data)
        return search(root->rightchild, x);
    else
        return search(root->leftchild,x);
}

void preorder(struct node * root){
    if(root != NULL){
        printf("%d \t", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->leftchild);
        printf("%d \t", root->data);
        inorder(root->rightchild);
    }
}
void postorder(struct node * root){
    if(root != NULL){
        postorder(root->rightchild);
        postorder(root->leftchild);
        printf("%d \t", root->data);
    }
}

struct node *find_minimum(struct node * root){
    if(root == NULL)
        return NULL;
    if(root->leftchild != NULL)
        return find_minimum(root->leftchild);
    return root;
}

struct node * delete(struct node * root, int x){
    if(root == NULL)
        return NULL;
    if(x > root->data)
        root->rightchild = delete(root->rightchild, x);
    else if(x < root->data)
        root->leftchild = delete(root->leftchild,x);
    else{
        if(root->leftchild == NULL && root->rightchild == NULL){
            free(root);
            return NULL;
        }
        else if(root->leftchild == NULL || root->rightchild == NULL){
            struct node *temp;
            if(root->leftchild == NULL){
                temp = root->rightchild;
            }
            else{
                temp = root->leftchild;
            }
            free(root);
            return temp;
        }
        else{
            struct node * temp = find_minimum(root->rightchild);
            root->data = temp->data;
            root->rightchild = delete(root->rightchild,temp->data);
             
        }
    }
    return root;
}

int main(){
    struct node * root;
    root = newnode(16);
    insert(root,14);
    insert(root,20);
    insert(root, 11);
    insert(root, 15);
    insert(root, 6);
    insert(root, 12);
    inorder(root);
    printf("\n");
    delete(root,14);
    inorder(root);
    printf("\n");
    delete(root, 12);
    inorder(root);
    printf("\n");
    delete(root,11);
    inorder(root);
    printf("\n");
    return 0;
    
}
