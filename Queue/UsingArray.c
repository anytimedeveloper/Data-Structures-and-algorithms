#include <stdio.h>



void enqueue(int *rear,int *front,int size,int queue[]){
    int data;
    if (*rear == size-1)
    {
        printf(" Overflow !!! \n");
    }
    else if(*front ==-1 && *rear==-1){
     printf("Enter the data you want to insert : ");
     scanf("%d ",data);
     *front=*rear=0;
     queue[*rear]=data;
    }
    else{
        printf("Enter the data you want to insert : ");
        scanf("%d ", data);
        (*rear)++;
        queue[*rear]=data;
    }   
}


void dequeue(int *rear,int *front,int queue[]){
    if (*front == -1 && *rear == -1)
    {
        printf("Underflow !!! \n ");
    }
    else if(*front == *rear){
        *front=*rear=-1;
    }
    else{
        printf("%d successfully deleted \n",queue[*front]);
        (*front)++;
    }
      
}

void display(int *rear,int *front,int queue[]){
    if (*front == -1 && *rear == -1)
    {
        printf("Underflow !!!   Queue is Empty  \n ");
    }
    else{
        printf("Elements of queue are : ");
        for (int i = *front; i < *rear+1; i++)
        {
            printf("%d   ",queue[i]);
        }
        printf("\n");
    }
}

void Front(int *rear, int *front, int queue[])
{
    if (*front == -1 && *rear == -1)
    {
        printf("Underflow !!!   Queue is Empty  \n ");
    }
    else{
        printf("Front of the queue is : %d \n ",queue[*front]);
    }
}
void Rear(int *rear, int *front, int queue[])
{
    if (*front == -1 && *rear == -1)
    {
        printf("Underflow !!!   Queue is Empty  \n ");
    }
    else{
        printf("Rear of the queue is : %d \n",queue[*rear]);
    }
}

void isFull(int *rear,int size){
    if (*rear == size-1)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Queue is not full");
    }
}
void isEmpty(int *rear, int *front){
    if (*front == -1 && *rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is not empty");
    }
}
int main()
{
    int size, choice = 1, front = -1, rear = -1, operation;
    printf("Enter the size of the queue : ");
    scanf("%d ", &size);
    int queue[size];
    while (choice)
    {
        printf("The operations you  can perform on queue are : \n ");
        printf(" 1. Enqueue \n 2. Dequeue \n 3. Front \n 4. Rear \n 5. isfull \n 6. isEmpty \n 7. Display \n");
        printf("Enter the operation you want to perform : ");
        scanf("%d ", &operation);
        switch (operation)
        {
        case 1:
            enqueue(&rear,&front,size,queue);
            break;
        case 2: 
            dequeue(&rear,&front,queue);
            break;
        case 3:
            Front(&rear, &front, queue);
            break;
        case 4:
            Rear(&rear, &front, queue);
            break;
        case 5:
            isFull(&rear,size);
            break;
        case 6:
            isEmpty(&rear, &front);
            break;
        case 7:
            display(&rear, &front, queue);
            break;
        default:
            printf("Please enter valid operation\n");
        }
        printf("Do you want to perform more operation 1 ? 0 : ");
        scanf("%d", &choice);
    }
    return 0;
}