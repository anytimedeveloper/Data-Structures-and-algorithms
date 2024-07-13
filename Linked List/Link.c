#include <stdio.h>
#include <stdlib.h>

 void main()
{

    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *newnode;
    struct node *temp;
    head = NULL;
    int choice, count = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0,1)?\n");
        scanf("%d", &choice);
    }
    printf("--------------------------------\n");
    temp = head;
    while (temp != 0)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
        count++;
    }
    {
        printf("\nCount=%d", count);
    }
}