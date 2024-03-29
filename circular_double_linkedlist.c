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
    }else
        {
            printf("\nMemory not avilable...node allocation is not possible");
        }
}
void display(node *temp)
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
    return;
}

void inst_beg()
{
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head->prev;
    printf("\n enter value to insert at first : ");
    scanf("%d",&ptr->data);
    ptr->prev = head->prev;
    ptr->next = head;
    while(p->next != head)
    {
        p=p->next;
    }
    head = ptr;
    p->next = ptr;
}
void inst_end()
{
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head->prev;
    printf("\n enter value to insert at end position  : ");
    scanf("%d",&ptr->data);
    while(p->next != head)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->prev =p;
    ptr->next = head;

}
int main()
{
    int choice;
    // building circular double linked list as input
    do
    {
        addNode();
        printf("\nIf you wish to add more data on the list enter 1 : ");
        scanf("%d", &choice);
    } while (choice == 1);

    display(head);
    inst_end();
    display(head);
    return 0;
}
