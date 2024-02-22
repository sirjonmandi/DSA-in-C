#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add(int);
void display();
struct node{
    int data;
    struct node *next;
};
struct node *head,*tail = NULL;
void ins_at_pos()
{
    struct node *ptr,*x,*y,*z;
    int c=1,pos,count = 1;
    y = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("enter a data for a particular possition ");
    scanf("%d",&y->data);
    printf("\nenter the possition to be inserted :");
    scanf("%d",&pos);
    x=head;
    ptr = head;
    while(ptr->next != head)
    {
        count++;
        ptr = ptr->next;
    }
    count++;
    if (pos>count)
    {
        printf("out of bound");
        return ;
    }
    while(c<pos)
    {
        z=x;
        x=x->next;
        c++;
    }
    y->next = x;
    z->next = y;
}
int main()
{
    add(1);
    add(2);
    add(3);
    display();
    ins_at_pos();
    display();
    return 0;
}
void add(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value; 
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }else{
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
    }else{
        printf("node of the circular linkedlist is :\n");
        do
        {
            printf("%d \n",current->data);
            current =current->next;

        } while (current->next != head);
        
    }
    
}
