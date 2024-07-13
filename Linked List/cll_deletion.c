#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createlist(struct node **tail, struct node *newnode)
{
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
        else
        {
            newnode->next = (*tail)->next;
            (*tail)->next = newnode;
            *tail = newnode;
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
void length(struct node *tail, struct node *temp, int *count)
{
    temp = tail->next;
    do
    {
        (*count)++;
        temp = temp->next;
    } while (temp != tail->next);
    printf("length is %d \n", *count);
}
void delete(struct node **tail,struct node *temp, struct node *nextnode, int count)
{
    int position;
    printf("Enter the position which node you want to delete : ");
    scanf("%d", &position);
    if (position > count || position < 1)
    {
        printf("Please enter a valid position");
    }
    else if (position == 1)
    {
        // delete first node
         temp=(*tail)->next;
         (*tail)->next=temp->next;
         free(temp);
    }
    else if (position == count)
    {
        // delete last node
       temp=(*tail)->next;
       while (temp->next->next!= (*tail)->next)
       {
           temp=temp->next;
       } 
       nextnode = *tail;
       temp->next=(*tail)->next;
       *tail=temp;
       free(nextnode);
    }
    else
    {
        // delete at position
        int pos = 1;
        temp = (*tail)->next;
        while (pos < position-1)
        {
            temp = temp->next;
            pos++;
        }
         nextnode=temp->next;
         temp->next=nextnode->next;
         free(nextnode);
    }
}
int main()
{
    struct node *tail, *temp, *newnode, *nextnode;
    int count = 0;
    tail = NULL;
    createlist(&tail, newnode);
    display(tail, temp);
    length(tail, temp, &count);
    delete(&tail, temp, nextnode, count);
    display(tail, temp);
    return 0;
}