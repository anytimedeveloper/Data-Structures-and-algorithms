#include<stdio.h>
#include<stdlib.h>
  
  struct node
  {
      int data;
      struct node* next;
  };

void  createlist(struct node **headnode,struct node* newnode,struct node* temp){
   int choice=1;
   while(choice){
       newnode=(struct node *)malloc(sizeof(struct node));
       printf("Enter data : ");
       scanf("%d",&newnode->data);
       newnode->next=0;
       if(*headnode==0){
           *headnode = temp = newnode;
       }
       else{
           temp->next=newnode;
           temp=newnode;
       }
       printf("Do you want to make new node? 1 : 0 =>");
       scanf("%d", &choice);
   }
  }

void display(struct node* head,struct node * temp){
    temp = head;
    while (temp!=0)
    {
      printf("%d  ",temp->data);
      temp=temp->next;
    }
    
    printf("\n");
  }
  void counter(struct node *head, struct node *temp, int *count)
  {
    temp = head;
    while (temp != 0)
    {
      temp = temp->next;
      (*count)++;
    }
  }

  void insertanywhere(struct node **head,struct node *newnode,struct node *temp,int count){
    int position;
    int i=1;
    printf("Enter the position where you want to insert data : ");
    scanf("%d",&position);
      temp=*head;
      while(i<position){
        temp=temp->next;
        i++;
      }
      if(temp->next==0){
        printf("Enter a valid position \n");
      }
      else if (position == 0)
      {
        printf("Enter a valid position \n");
      }
      else{
      newnode = (struct node *)malloc(sizeof(struct node));
      printf("Enter data you want to insert : ");
      scanf("%d", &newnode->data);
      newnode->next=temp->next;
      temp->next=newnode;
      }
  }
int main(){
  struct node *newnode,*temp,*head;
  int count =0;
  head =0;
  createlist(&head,newnode,temp);
  display(head,temp);
  counter(head,temp,&count);
  insertanywhere(&head,newnode,temp,count);
  display(head, temp);
}