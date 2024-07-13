#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void createlist(struct node **tail,struct node *newnode,struct node *temp){
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (*tail == NULL)
        {
            *tail = newnode;
            (*tail)->next = newnode;
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
         printf("%d   ",temp->data);
         temp=temp->next;
     } while (temp != tail->next);
         printf("\n");
    }
int main(){
 struct node *tail,*newnode,*temp;
 tail=NULL;
 createlist(&tail,newnode,temp);
 display(tail,temp);
return 0;
}