#include<stdio.h>
#include<stdlib.h>

 struct node
 {
     int data;
     struct node *previous;
     struct node *next;
 };

 void createlist(struct node **head, struct node **tail, struct node *newnode, struct node *temp) {
     int choice=1;
     while(choice){
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("Enter data : ");
     scanf("%d",&newnode->data);
     newnode->previous=NULL;
     newnode->next=NULL;
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

 void reverse(struct node **head,struct node **tail,struct node *temp,struct node *nextnode,struct node *currentnode){
     currentnode=*head;
     while(currentnode!=NULL){
     nextnode = currentnode->next;
     currentnode->next=currentnode->previous;
     currentnode->previous=nextnode;
     currentnode=nextnode;
     }
     temp=*head;
     *head=*tail;
     *tail=temp;
 }
 int main()
 {
     struct node *head, *tail, *newnode, *temp,*nextnode,*currentnode;
     head = NULL;
     createlist(&head, &tail, newnode, temp);
     display(head, temp);
     reverse(&head,&tail,temp,nextnode,currentnode);
     display(head, temp);
     return 0;
 }