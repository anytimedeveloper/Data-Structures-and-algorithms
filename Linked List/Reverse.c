#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void createList(struct node **headnode, struct node *newnode, struct node *temp)
{
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (*headnode == 0)
        {
            *headnode = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to make new node? 1 : 0 =>");
        scanf("%d", &choice);
    }
}

void reverse(struct node **headnode, struct node *currentnode, struct node *previousnode, struct node *nextnode)
{
    previousnode = 0;
    currentnode = nextnode = *headnode;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currentnode->next = previousnode;
        previousnode = currentnode;
        currentnode = nextnode;
   }
   *headnode=previousnode;
}

void display(struct node *headnode, struct node *temp)
{
     temp = headnode;
    while (temp != 0)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *head, *newnode, *temp, *previousnode, *currentnode, *nextnode;
    head=0;
    createList(&head,newnode,temp);
    printf("Before reversing the linked list is: ");
    display(head,temp);
    printf("After reversing the linked list is: ");
    reverse(&head,currentnode,previousnode,nextnode);
    display(head,temp);
    
}