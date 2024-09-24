#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int arr[MAX];
    int front, rear;
} Queue;

void initialize(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return 1;
    return 0;
}

bool isFull(Queue *q)
{
    if ((q->rear + 1) % MAX == q->front)
        return 1;
    return 0;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("\n Queue Overflow");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("\n Enqueued Element %d", value);
}

int dequeue(Queue *q)
{
    int ele;
    if (isEmpty(q))
    {
        printf("\n Queue underflow");
        return -1;
    }
    ele = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    return ele;
}

int front(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\n Queue underflow");
        return -1;
    }
    return q->arr[q->front];
}

int rear(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\n Queue underflow");
        return -1;
    }
    return q->arr[q->rear];
}

int main()
{
    Queue queue;
    int choice, val, ele;
    char ch;
    initialize(&queue);
    printf("\nEnter your choice:");
    printf("\n 1.Enqueue \n 2.Dequeue \n 3.IsFull \n 4.IsEmpty \n 5.Front \n 6.Rear \n 0.Exit");
    scanf("%d", &choice);
    do{

        switch (choice)
        {
        case 1:
            printf("\n Enter Element to enqueue:");
            scanf("%d", &val);
            enqueue(&queue, val);
            break;
        case 2:
            ele = dequeue(&queue);
            printf("\n The poped Element is %d", ele);
            break;
        case 3:
            ele = isFull(&queue);
            if(ele == 1)
                printf("\n The queue is full");
            else
                printf("\n The queue is not full");
            break;
        case 4:
            ele = isEmpty(&queue);
            if(ele == 1)
                printf("\n The queue is Empty");
            else
                printf("\n The queue is not Empty");
            break;

        case 5:
            ele = front(&queue);
            printf("\n The element on the front of the queue is %d",ele);
            break;

        case 6:
            ele = rear(&queue);
            printf("\n The element on the rear of the queue is %d",ele);
            break;
        case 0:
            exit(0);
        
        default:
            printf("\n Enter the correct choice");
        }
        printf("\n Do you want to continue:");
        scanf("%c",&ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}
