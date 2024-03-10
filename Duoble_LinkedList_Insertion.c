#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};
struct node *head,*tail = NULL;

void addNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    if (head == NULL)
    {
        head = tail = newNode;
        head->previous = NULL;
        tail->next = NULL;
    }else
    {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nlist is empty\n");
    }else
    {
        struct node *current = head;
        printf("list is\n");
        while (current != NULL)
        {
            printf("%d \t",current->data);
            current = current->next;
        }
    }
    
}

void display_rev()
{
    struct node *current = tail;
    printf("\nreverse list is :\n");
    while (current != NULL)
    {
        printf("%d \t",current->data);
        current = current->previous;
    }
    
}

void insert_big()
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the value that you want to insert at beggining : ");
    scanf("%d",&newNode->data);
    if (head == NULL)
    {
        head = tail = newNode;
        head->previous = NULL;
        tail->next = NULL;
    }else{
        newNode->next = head;
        newNode->previous = NULL;
        head = newNode;
    }
    
}

void insert_end()
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the number that you want to insert at end : ");
    scanf("%d",&newNode->data);
    if (head == NULL)
    {
        printf("list is empty !");
    }else
    {
        newNode->previous = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

// void insert_any()
// {
//     int pos;
//     int loc = 1;
//     struct node *newNode = (struct node*)malloc(sizeof(struct node));
//     struct node *current = head;
//     printf("\nenter the position where you what to insert the value : \n");
//     scanf("%d",&pos);
//     printf("\nenter the value : \n");
//     scanf("%d",&newNode->data);
//     if (pos == 1)
//     {
//         newNode->next = head;
//         newNode->previous = NULL;
//         head = newNode;
//     }else{
//         while (pos-1 >= loc)
//         {
//             current = current->next;
//             loc++;
//         }
//         current->previous = newNode;
        
//         newNode->next = current;
//     }
// }

int main()
{
    addNode(1);
    addNode(2);
    addNode(3);
    display();

    insert_end();
    display();

    getch();
    return 0;
}
