#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};

void createlist(struct node **head, struct node *newnode, struct node *temp, struct node **tail){
    int choice=1;
    while(choice){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->previous=NULL;
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->previous=temp;
        temp=newnode;
        *tail=temp;
    }
    printf("Do you want to make new node? 1 : 0 =>");
    scanf("%d", &choice);
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

void length(struct node *head,struct node *temp,int *count){
  temp=head;
  while (temp!=NULL)
  {
      temp=temp->next;
      (*count)++;
  }
  printf("length of this list is : %d",*count);
  printf("\n");
}

void deletion(struct node **head, struct node *temp, struct node **tail, int count, struct node *prenode,struct node *nextnode)
{
    int position,i=1;
    printf("Enter the position you want to delete : ");
    scanf("%d",&position);
    if (position>count || position<0)
    {
        printf("Please enter a valid position\n ");
    }
    else if(position==1){
        temp=*head;
        *head=temp->next;
        nextnode=temp->next;
        nextnode->previous==NULL;
        free(temp);
    }
    else if(position==count){
        // temp=*head;
        // while (temp->next!=NULL)
        // {
        //     temp=temp->next;
        // }
        // if(temp->next==NULL){
        //     prenode=temp->previous;
        //     prenode->next=NULL;
        //     free(temp);
        // }
        temp=*tail;
        *tail=temp->previous;
        temp->previous->next=NULL;
        free(temp);
    }
    else{
      temp=*head;
      while (i!=position)
      {
         temp=temp->next;
         i++;
      }
      prenode=temp->previous;
      nextnode=temp->next;
      prenode->next=nextnode;
      nextnode->previous=prenode;
      free(temp);
    }
}

    int main()
{
    struct node *head, *newnode, *temp, *tail, *prenode,*nextnode;
    head = NULL;
    int count = 0;
    createlist(&head, newnode, temp, &tail);
    display(head, temp);
    length(head, temp, &count);
    deletion(&head, temp, &tail,count,prenode,nextnode);
    display(head, temp);
    return 0;
}