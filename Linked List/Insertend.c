#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
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

void insertend(struct node *headnode, struct node *newnode, struct node *temp)
{
    temp = headnode;
    while(temp->next!=0){
        temp = temp->next;
    }
    if (temp->next == 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data you want to insert at end : ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        temp->next = newnode;
    }
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

int main()
{
    struct node *head, *newnode, *temp, *previousnode, *currentnode, *nextnode;
    head = 0;
    createList(&head, newnode, temp);
    printf("Before  inserting ,the linked list is: ");
    display(head, temp);
    insertend(head, newnode, temp);
    printf("After inserting ,the linked list is: ");
    display(head, temp);
}