#include<stdio.h>
# include<stdlib.h>
  
struct node
{
    int data;
    struct node *next;
};

void createlist(struct node **head,struct node *newnode,struct node *temp,struct node **tail){
    int choice=1;
    while (choice)
    {
   newnode=(struct node *)malloc(sizeof(struct node));
   printf("Enter data : ");
   scanf("%d",&newnode->data);
   if(*head==NULL){
       *head=temp=newnode;
   }
   else{
    temp->next=newnode;
    temp=newnode;
    *tail=temp;  
   }
   temp->next=*head;
   printf("Do you want to make new node? 1 : 0 =>");
   scanf("%d", &choice);
 }
}

void display(struct node *head,struct node *temp,struct node *tail,int *count){
    temp=head;
    do{
        printf("%d  ",temp->data);
        temp=temp->next;
        (*count)++;
    } while (temp!= tail->next);
        printf("\n");
        printf("Length is %d",*count);
}
int main(){
    int count =0;
    struct node *head,*newnode,*temp,*tail;
    head=NULL;
    createlist(&head,newnode,temp,&tail);
    display(head,temp,tail,&count);
return 0;
}