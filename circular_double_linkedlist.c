#include <stdio.h>
#include <stdlib.h>
// cicular double linked list structure
typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} node;

node *head = NULL;
void addNode()
{
    node *temp, *temp1;
    temp = (node *)malloc(sizeof(node));
    if (temp != NULL)
    {
        printf("\nEnter the element in the list : ");
        scanf("%d", &temp->data);
        temp->next = head;
        if (head == NULL)
        {
            head = temp;
            temp->prev = head;
            temp->next = head;
        }
        else
        {
            temp1 = head;
            while (temp1->next != head)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
            temp->prev = temp1;
        }
    }
    else
    {
        printf("\nMemory not avilable...node allocation is not possible");
    }
}
void display(node *temp)
{
    if (head != NULL)
    {
        // now temp1 is head basically
        node *temp1 = temp;
        printf("The list is as follows :\n%d ", temp->data);
        temp = temp->next;
        // which not circle back to head node
        while (temp != temp1)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    else{
        printf("\nUnderflow\n");
    }
}

void inst_beg()
{
    if (head == NULL)
    {
        printf("\nlist is not created you cann't insert at first \n");
        return;
    }
    
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head->prev;
    printf("\n enter value to insert at first : ");
    scanf("%d", &ptr->data);
    ptr->prev = head->prev;
    ptr->next = head;
    while (p->next != head)
    {
        p = p->next;
    }
    head = ptr;
    p->next = ptr;
}
void inst_end()
{
    if (head == NULL)
    {
        printf("\nlist is not created you cann't insert at end :) \n");
        return;
    }
    
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head->prev;
    printf("\n enter value to insert at end position  : ");
    scanf("%d", &ptr->data);
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = head;
}
int main()
{
    int choice = 1;
    while (choice != 5) {
        printf("\ncircular linked list program \n");
        printf("1.add node\n");
        printf("2.add node at first position\n");
        printf("3.add node at end position\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("\nenter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:addNode();
            break;
        case 2:inst_beg();
            break;
        case 3:inst_end();
            break;
        case 4:display(head);
            break;
        case 5:exit(1);
            
        default:printf("wrong choice");
            break;
        }
    }
    return 0;
}
