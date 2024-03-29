#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Circular Linked List insertion and deletion at any position 
void add(int);
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail = NULL;
void ins_at_pos()
{
    struct node *ptr, *x, *y, *z;
    int c = 1, pos, count = 1;
    y = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("enter a data for a particular possition ");
    scanf("%d", &y->data);
    printf("\nenter the possition to be inserted :");
    scanf("%d", &pos);
    x = head;
    ptr = head;
    if (pos == 1)
    {
        while (ptr->next != head)
        {
            // count++;
            ptr = ptr->next;
        }
        ptr->next = y;
        y->next = head;
        head = y;
    }
    else
    {

        while (ptr->next != head)
        {
            count++;
            ptr = ptr->next;
        }
        count++;
        if (pos > count)
        {
            printf("out of bound\n");
            return;
        }
        while (c < pos)
        {
            z = x;
            x = x->next;
            c++;
        }
        y->next = x;
        z->next = y;
    }
}
void del_at_pos()
{
    struct node *x, *y;
    int c = 1, pos;
    printf("\n Enter the position to be deleted:");
    scanf("%d", &pos);
    x = head;
    if (head == NULL)
        printf("\n List is empty");
    else if (pos == 1)
    {
        while (x->next != head)
        {
            x = x->next;
        }
        y = head;
        x->next = y->next;
        head = y->next;
        free(y);
    }
    else
    {

        x = head;

        while (c < pos)
        {
            y = x;
            x = x->next;
            c++;
        }
        y->next = x->next;
        free(x);
    }
}
int main()
{
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    display();
    ins_at_pos();
    display();
    return 0;
}
void add(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}
void display()
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("list is empty!");
    }
    else
    {
        printf("node of the circular linkedlist is :\n");
        do
        {
            printf("%d \n", current->data);
            current = current->next;
        } while (current != head);
    }
}