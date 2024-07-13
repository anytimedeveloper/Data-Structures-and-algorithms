#include<stdio.h>
#include<stdlib.h>

 struct node{
     int data;
     struct node *next;
 };


void createlist(struct node **tail,struct node *newnode){
    int choice =1;
    while(choice){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (*tail==NULL)
    {
        *tail=newnode;
        (*tail)->next=newnode;
    }
    else{
        newnode->next=(*tail)->next;
        (*tail)->next=newnode;
         *tail=newnode;
    }
    printf("Do you want to make new node? 1 : 0 =>");
    scanf("%d", &choice);
}
}

void display(struct node *tail,struct node *temp){
    temp=tail->next;
    do{
        printf("%d  ",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");
}
void length(struct node *tail, struct node *temp,int *count) {
    temp = tail->next;
    do
    {
        (*count)++;
        temp = temp->next;
    } while (temp != tail->next);
    printf("length is %d \n",*count);
}
void insert(struct node **tail, struct node *newnode,struct node *temp,struct node *nextnode, int count) {
    int position;
    printf("Enter the position you want to insert at : ");
    scanf("%d",&position);
    if(position>count || position<0){
        printf("Please enter a valid position");
    }
    else if(position==0){
        //insert at first
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        temp=(*tail)->next;
        newnode->next=temp;
        (*tail)->next=newnode;

    }
    else if(position==count){
       // insert at end
       newnode = (struct node *)malloc(sizeof(struct node));
       printf("Enter data : ");
       scanf("%d", &newnode->data);
       temp=(*tail)->next;
       (*tail)->next=newnode;
       newnode->next=temp;
       (*tail)=newnode;
    }
    else{
        //insert at position
        int pos=1;
        temp=(*tail)->next;
        while(pos<position){
            temp=temp->next;
            pos++;
        }
        if(pos==position){
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data : ");
            scanf("%d", &newnode->data);
            nextnode=temp->next;
            temp->next=newnode;
            newnode->next=nextnode;
        }

    }
}
int main()
{
    struct node *tail,*temp,*newnode,*nextnode;
    int count=0;
    tail=NULL;
    createlist(&tail,newnode);
    display(tail,temp);
    length(tail,temp,&count);
    insert(&tail,newnode,temp,nextnode,count);
    display(tail, temp);
    return 0;
}