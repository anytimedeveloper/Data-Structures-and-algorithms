#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *previous;
    int data;
    struct node *next;
};


void createlist(struct node **head,struct node *newnode,struct node *temp){
    int choice=1;
    while(choice){
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter data : ");
  scanf("%d",&newnode->data);
  newnode->previous=NULL;
  newnode->next=NULL;
  if (*head==NULL)
  {
      *head=temp=newnode;
  }
  else{
   temp->next=newnode;
   newnode->previous=temp;
   temp=newnode;
  }
  printf("Do you want to make new node? 1 : 0 =>");
  scanf("%d",&choice);
    }
}

void display(struct node *head,struct node *temp){
    temp=head;
    while (temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}
int main(){
    struct node *head,*newnode,*temp,*tail;
    head=NULL;
    createlist(&head,newnode,temp);
    display(head,temp);
return 0;
}