#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int binarySearch(int arr[],int low,int high,int ele){
    int mid = (low+high)/2;
    if(arr[mid] == ele){
        return mid;
    }
    if(arr[mid] > ele){
        return binarySearch(arr,low,mid-1,ele);
    }
    else{
        return binarySearch(arr,mid+1,high,ele);
    }
    return -1;
}

void main(){
    int arr[MAX],low,high,i,result,ele;
    printf("\n Enter the array elements:");
    for(i = 0;i<MAX;i++){
        scanf("%d",&arr[i]);
    }

    printf("\n The sorted array is \n ");
    for(i=0;i<MAX;i++){
        printf("%d \t",arr[i]);
    }
    low = 0;
    high = MAX;
    printf("\n Enter element to search:");
    scanf("%d",&ele);
    result = binarySearch(arr,low,high,ele);

    if(result == -1){
        
        printf("\n The search element is not found");
    }
    else{
        printf("\n The search element is found at %d",result);
    }
}
