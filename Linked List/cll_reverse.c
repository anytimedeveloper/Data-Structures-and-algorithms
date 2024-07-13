#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void createlist(struct node **tail,struct node *newnode){
    int choice=1;
    while (choice)
    {
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
            (*tail)=newnode;
        }
        printf("Do you want to make new node? 1 : 0 =>");
        scanf("%d", &choice);
    }
    
}

void display(struct node *tail, struct node *temp)
{
    temp = tail->next;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

void reverse(struct node **tail,struct node *currentnode,struct node *nextnode,struct node *temp,struct node *prenode){
    currentnode=(*tail)->next;
    nextnode=currentnode->next;
    while (currentnode!=(*tail))
    {
        prenode=currentnode;
       currentnode=nextnode;
       nextnode=currentnode->next;
       currentnode->next=prenode;
    }
    nextnode->next=(*tail);
    (*tail)=nextnode;
}

int main(){
    struct node *tail,*newnode,*temp,*currentnode,*nextnode,*prenode;
    tail=NULL;
    createlist(&tail,newnode);
    display(tail,temp);
    reverse(&tail,currentnode,nextnode,temp,prenode);
    display(tail, temp);
    return 0;
}