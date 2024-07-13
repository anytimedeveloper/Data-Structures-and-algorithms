#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

void createlist(struct node **head, struct node **tail, struct node *newnode)
{
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->previous = NULL;
        if (*head == NULL)
        {
            *head = *tail = newnode;
            (*head)->next = *head;
            (*head)->previous = *head;
        }
        else
        {
            (*tail)->next = newnode;
            newnode->previous = (*tail);
            newnode->next = (*head);
            (*head)->previous = newnode;
            *tail = newnode;
        }
        printf("Do you want to make new node? 1 : 0 =>");
        scanf("%d", &choice);
    }
}

void display(struct node *head, struct node *tail, struct node *temp)
{
    temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
        printf("\n");
}

int main()
{
    struct node *newnode, *head, *tail, *temp;
    head = NULL;
    createlist(&head, &tail, newnode);
    display(head, tail, temp);
    return 0;
}