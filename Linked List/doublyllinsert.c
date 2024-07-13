#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

void createlist(struct node **head, struct node *newnode, struct node *temp, struct node **tail)
{
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->previous = NULL;
        if (*head == NULL)
        {
            *head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->previous = temp;
            temp = newnode;
            *tail = temp;
        }
        printf("Do you want to make new node? 1 : 0 =>");
        scanf("%d", &choice);
    }
}
void display(struct node *head, struct node *temp)
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void counter(struct node *head, struct node *temp, int *count)
{
    temp = head;
    while (temp != 0)
    {
        (*count)++;
        temp = temp->next;
    }
    printf("Length of doubly linked list is : %d", *count);
    printf("\n");
}

void isertionatbeignning(struct node **head, struct node *newnode, struct node *temp)
{
    temp = *head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data you want to insert : ");
    scanf("%d", &newnode->data);
    newnode->next = temp;
    newnode->previous = NULL;
    *head = newnode;
}

void insertionatposition(struct node *head, struct node *newnode, struct node *temp, int count)
{
    int position, i = 1;
    temp = head;
    printf("Enter the position you want to insert : ");
    scanf("%d", &position);
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    if (position > count)
    {
        printf("Please enter a valid position ");
    }
    else if (temp->next == NULL)
    {
        printf("Please enter a valid position ");
    }
    else if (position == 0)
    {
        printf("Please enter a valid position ");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        newnode->previous = temp;
        temp->next = newnode;
    }
}

void insertionatend(struct node **tail, struct node *newnode, struct node *temp)
{
    temp = *tail;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp->next = newnode;
    newnode->previous = temp;
    *tail = newnode;
}
int main()
{
    struct node *head, *newnode, *temp, *tail;
    head = NULL;
    int count = 0;
    int choice;
    createlist(&head, newnode, temp, &tail);
    display(head, temp);
    counter(head, temp, &count);
    printf(" 1. Insertion at beignning \n 2. Insertion at a position \n 3. Insertion at end \n");
    printf("Where you want to insert in doubly linked list : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        isertionatbeignning(&head, newnode, temp);
        break;
    case 2:
        insertionatposition(head, newnode, temp, count);
        break;
    case 3:
        insertionatend(&tail, newnode, temp);
        break;
    default:
        printf("Please enter a valid choice");
    }
    display(head, temp);
    return 0;
}