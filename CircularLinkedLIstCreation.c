#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head ,*tail = NULL;
void add(int data)
{
    // printf("i am in add function %d\n",data);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL)
    {
        // printf("i am inside head=null condition\n");
        head = newNode;
        tail = newNode;
    }
    else
    {
        // printf("i am inside head=null else condition\n");
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}
void display()
{
    // printf("i am in display function\n");
    struct node *current = head;
    if (head == NULL)
    {
        printf("list is empty !");
    }
    else
    {
        printf("node of the circular linkedlist is : \n");
        do
        {
            printf("%d \n", current->data);
            current = current->next;
        } while (current != head);
    }
}

void beg_inst(int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    if (ptr == NULL)
    {
        printf("\n OverFlow !");
    }else{
        ptr->data = data;
        if (head == NULL)
        {
            head = ptr;
            ptr->next=head;
        }else{
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\n node is inserted !");
    }
    
}

void main()
{
    add(1);
    add(2);
    add(3);
    add(4);
    display();
    beg_inst(5);
    printf("\n displaying new node after add node in the begnning\n");
    display();
}