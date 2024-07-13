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
            newnode->next = newnode;
            newnode->previous = newnode;
        }
        else
        {
            (*tail)->next = newnode;
            newnode->previous = *tail;
            newnode->next = *head;
            (*head)->previous = newnode;
            *tail = newnode;
        }
        printf("Do you want to make new node? 1 : 0 =>");
        scanf("%d", &choice);
    }
}

void display(struct node *head, struct node *temp, int *count)
{
    temp = head;
    do
    {
        printf("%d  ", temp->data);
        (*count)++;
        temp = temp->next;
    } while (temp != head);

    printf("\n");
    printf("Length is %d", *count);
    printf("\n");
}

void delete(struct node **head, struct node **tail, struct node *newnode, struct node *temp, int count)
{
    int position;
    printf("Enter the position where you want to delete : ");
    scanf("%d", &position);

    if (position > count || position < 1)
    {
        printf("\nPlease enter a valid position");
    }
    else if (position == 1)
    {
       temp=*head;
       temp->next->previous=*tail;
       *head=temp->next;
       (*tail)->next=*head;
       free(temp);
    }
    else if (position == count)
    {
        temp=*tail;
        temp->previous->next=*head;
        *tail=temp->previous;
        (*head)->previous=*tail;
        free(temp);
    }
    else
    {
        int i = 1;
        temp = *head;
        while (i < position)
        {
            temp = temp->next;
            i++;
        }
       temp->previous->next=temp->next;
       temp->next->previous=temp->previous;
       free(temp);
    }
}

int main()
{
    struct node *head, *tail, *newnode, *temp;
    int count = 0;
    head = NULL;
    createlist(&head, &tail, newnode);
    printf("Before deletion : ");
    display(head, temp, &count);
    delete(&head, &tail, newnode, temp, count);
    count = 0;
    printf("After deletion : ");
    display(head, temp, &count);
    return 0;
}