#include <stdio.h>


void push(int size,int stack[],int *top){
    int data;
     if (*top == size-1)
     {
        printf("Stack Overflow !!!\n");
     }
     else{
        printf("Enter the data you want to insert : ");
        scanf("%d",&data);
        (*top)++;
        stack[*top]=data;
     } 
}
void pop(int stack[], int *top)
{
    int data;
    if (*top == -1)
    {
        printf("Stack Underflow !!!\n");
    }
    else
    {
        data= stack[*top];
        (*top)--;
        printf("%d successfully popped \n",data);
    }
}
void peek(int stack[],int *top){
    int value = *top;
    if (*top==-1)
    {
       printf("Stack is empty\n");
    }
    else{
        printf("The top element of the stack is : %d \n",stack[value]);
    } 
}

void isEmpty(int *top){
    if (*top == -1)
    {
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is having elements\n");
    }
}
int isFull(int size,int *top){
    if (*top == size-1)
    {
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }
}

void display(int stack[],int *top){
    printf("Stack elements are :");

    for (int i = 0; i <=*top; i++)
    {
       printf("%d  ",stack[i]);
    }
    printf("\n");
}

int main()
{
    int top = -1;
    int choice = 1;
    int size;
    printf("Enter size of the stack :");
    scanf("%d", &size);
    int stack[size];
    printf("Your Stack using Array is Ready perform operations on it\n");
    while (choice)
    {
        int operation;
        printf("Select  your choice\n");
        printf("1. push \n2. pop \n3. peek \n4. isEmpty \n5. isFull \n6. Display\n");
        printf("------------------------------------------------------------------\n");
        printf("-------Choose operation--------\n");
        printf("Enter the operation you want to perform : ");
        scanf("%d", &operation);
        switch (operation)
        {
            case 1:
            push(size,stack,&top);
            break;
            case 2:
            pop(stack,&top);
            break;
            case 3:
            peek(stack,&top);
            break;
            case 4:
            isEmpty(&top);
            break;
            case 5:
            isFull(size,&top);
            break;
            case 6:
            display(stack,&top);
            break;
            default:
            printf("Please enter valid operation\n");
        }
        printf("Do you want to perform more operation 1 ? 0 : ");
        scanf("%d", &choice);
    }

    return 0;
}