#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

void insert_begin(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }
}
void insert_end(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
}
void delete_begin()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    if (temp == last)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    free(temp);
}

void delete_end()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    if (temp == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }

        temp->next = last->next;
        free(last);
        last = temp;
    }
}

void display()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first)\n");
}

int main()
{
    struct node*head = NULL;
    int data,choice,key;

    while (1)
    {
        printf("1. Insert at End\n");
        printf("2. Delete node\n");
        printf("3. Print List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data at insert: ");
            scanf("%d", &data);
            insertEnd(data);
            break;

        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &key);
           deletenode(&head,key);
            break;

        case 3:
            printf("CIRCULAR LINKED LIST:");
            printfList(head);
            break;

        case 0:
            printf("exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
  }
        

