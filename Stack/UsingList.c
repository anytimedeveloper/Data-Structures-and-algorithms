#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
};

void push(struct node **top,struct node *newnode){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next= *top;
    *top=newnode;
    
}
void display(struct node **top,struct node *temp){
    temp=*top;
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        printf("Stack elements are : ");
        while (temp!=NULL)
        {
           printf("%d  ",temp->data);
           temp=temp->next;
        }
        printf("\n");
    }
}

void pop(struct node **top,struct node *temp){
     temp=*top;
     if (top == NULL)
     {
         printf("stack is empty\n");
     }
     else
     {
        printf("%d successfully deleted \n",(*top)->data);
        *top=(*top)->next;
        free(temp);
     }
}
int main(){
    struct node *top,*newnode,*temp;
    top=NULL;
    int ch;
    int choice =1;
    while(choice){
    printf("Perform operations on stack \n");
    printf("1. push  \n 2. display  \n  3. pop \n");
    printf("Which operation you want to perform : \n ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
    push(&top,newnode);
    break;
    case 2:
    display(&top,temp);
    break;
    case 3:
    pop(&top, temp);
    break;
    default: 
    printf("enter a proper choice \n");
    }
    printf("Do you want to continue 1 ? 0 : ");
    scanf("%d",&choice);
    printf("\n");
    }
    return 0;
}