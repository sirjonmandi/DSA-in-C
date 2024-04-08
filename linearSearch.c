#include<stdio.h>
#include<conio.h>
#define size 5
int main()
{
    int a[size];
    int i,f=0,item;
    printf("enter five  elements");
    for ( i = 0; i < size; i++)
        scanf("%d",&a[i]);
    printf("enter a element to be searched : ");
    scanf("%d",&item);
    for ( i = 0; i < size; i++)
    {
        if (a[i]==item)
        {
            f=1;
            break;
        }
    }
    if (f==1)
    {
        printf("%d element is found at index position  %d",item,i);
    }else{
        printf("element not found");
    }
    getch();
    return 0;
}