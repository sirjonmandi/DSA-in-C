#include<stdio.h>  
#include<stdlib.h>  
void create(int);  
void deletion_beginning();  
struct node  
{  
    int data;  
    struct node *next;  
    struct node *prev;  
};  
struct node *head;  
void create(int item)  
{  
   struct node *ptr = (struct node *) malloc(sizeof(struct node));  
   struct node *temp;   
    if(ptr == NULL)  
   {  
       printf("\nOVERFLOW\n");  
   }  
   else  
   {  
        ptr->data=item;  
       if(head == NULL)  
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       }  
       else  
       {  
          temp = head;  
          while(temp->next !=head)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          head -> prev = ptr;  
           ptr -> next = head;  
        }  
   }  
     
} 
void display()
{
    struct node* temp=head;
    printf("The list is as follows :\n%d ", temp->data);
    temp = temp->next;    
    while (temp != head) 
	{
    printf("%d ", temp->data);
    temp = temp->next;
    }
   } 

void last_delete()  
{  
struct node *ptr, *preptr;    
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW\n");  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nNode Deleted\n");  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        printf("\nNode Deleted\n");  
    }  
}  
int main()
{
create(1);
create(2);
create(3);
create(4);
display();
last_delete();
display();
return 0;
}