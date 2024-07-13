#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createlist(struct node **head, struct node *newnode, struct node *temp)
{
    int choice=1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (*head == NULL)
        {
            *head = temp = newnode;
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

void display(struct node *head, struct node *temp)
{
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
    printf("\n");
}

void deletionatbeignning(struct node **head, struct node *temp, struct node *nextnode)
{
    temp = *head;
    nextnode = temp->next;
    *head = nextnode;
    free(temp);
}
void deletionatanywhere(struct node *head, struct node *temp, int count, struct node *nextnode)
{
    int position, i = 1;
    temp = head;
    printf("Enter the position you want to delete data : ");
    scanf("%d", &position);
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (position > count)
    {
        printf("Enter a valid position");
    }
    else if (position == 0)
    {
        printf("Enter a valid position");
    }
    else if (temp->next == NULL)
    {
        printf("Enter a valid position");
    }
    else
    {
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}
void deletionatend(struct node *head, struct node *temp, struct node *prenode)
{
    temp = head;
    while (temp->next != NULL)
    {
        prenode = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        prenode->next = NULL;
        free(temp);
    }
}

int main()
{
    struct node *head, *newnode, *temp, *nextnode, *prenode;
    head = NULL;
    int choose, count = 0;
    createlist(&head, newnode, temp);
    display(head, temp);
    counter(head, temp, &count);
    printf(" 1. Deletion at beignning \n 2. Deletion at anywhere \n 3. Deletion at end\n");
    printf("Enter the choice you want to delete at :");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        deletionatbeignning(&head, temp, nextnode);
        break;
    case 2:
        deletionatanywhere(head, temp, count, nextnode);
        break;
    case 3:
        deletionatend(head, temp, prenode);
        break;
    default:
        printf("Enter a valid choice");
    }
    display(head, temp);
}