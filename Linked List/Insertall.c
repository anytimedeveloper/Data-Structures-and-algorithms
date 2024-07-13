#include<stdio.h>
#include<stdlib.h>
  
struct node{
    int data;
    struct node *next;
};

void createlist(struct node **head,struct node *newnode,struct node *temp){
    int choice=1;
    while(choice){
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter data : ");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if (*head==NULL)
  {
      *head=temp=newnode;
  }
  else{
      temp->next=newnode;
      temp=newnode;
  }
  printf("Do you want to make new node? 1 : 0 =>");
  scanf("%d",&choice);
  
 }
}
void display(struct node *head,struct node *temp){
   temp=head;
   while(temp!=NULL){
       printf("%d  ",temp->data);
       temp=temp->next;
   }
   printf("\n");
}
void length(struct node *head, struct node *temp,int *count)
{
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        (*count)++;
    }
    printf("length of linked list is : %d",*count);
    printf("\n");
}
void insertionatbeignning(struct node **head,struct node *newnode,struct node* temp){
    temp = *head;
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next=temp;
    *head=newnode;
}
void insertionatanywhere(struct node *head,struct node *newnode,struct node* temp,int count){
    int position;
    int i=1;
    temp=head;
    printf("Enter the position you want to insert at : ");
    scanf("%d", &position);
    while (i<position)
    {
        temp=temp->next;
        i++;
    }
    
    if(position>count){
        printf("Enter a valid position");
    }
    else if(position==0){
        printf("Enter a valid position");
    }
    else if(temp->next==0){
        printf("Enter a valid position");
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

 void insertionatend(struct node *head,struct node *newnode,struct node *temp){
    temp = head;
    while(temp->next!=0){
        temp=temp->next;
    }
    if(temp->next==0){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        temp->next=newnode;
    }

}

int main(){
    struct node *head,*newnode,*temp;
    int count=0;
    int choose;
    head=NULL;
    createlist(&head,newnode,temp);
    display(head,temp);
    length(head,temp,&count);
    printf("1. Insert at beigning \n 2. Insert at anywhere  \n 3. Insert at end\n");
    printf("Where you want to insert data : ");
    scanf("%d",&choose);
     switch (choose)
    {
    case 1: 
        insertionatbeignning(&head,newnode,temp);
        break;
    case 2:
        insertionatanywhere(head, newnode, temp, count);
        break;
     case 3:
         insertionatend(head, newnode, temp);
         break;
    default:
        printf("Please enter a valid choice");
        }
     display(head, temp);
        return 0;
}