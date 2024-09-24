#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void main(){
    int arr[MAX];
    int i,ele,flag = 0;
    printf("\n Enter the array elements:\n");
    for(i = 0;i<MAX; i++){
        scanf("%d",&arr[i]);
    }
    printf("\n The array elements are:\n");
    for(i=0;i<MAX;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n Enter element to search:");
    scanf("%d",&ele);
    for(i=0;i<MAX;i++){
        if(ele == arr[i]){
            flag = 1;
            printf("\n The element is found at %d",i);
        }
    }
    if(flag == 0){
        printf("\n The element is not found");
    }
}
