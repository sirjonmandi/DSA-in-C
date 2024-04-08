#include<stdio.h>
#include<conio.h>
#define size 5

int main()
{
    int a[size];
    int lb = 0,ub=size-1,mid=0,f=0,item;
    printf("enter five elemtnts : ");
    for (int  i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter element to be searched : ");
    scanf("%d",&item);
    while (lb<=ub)
    {
        mid = (lb+ub)/2;
        if (a[mid]==item)
        {
            f=1;
            break;
        }else if (a[mid]<=item)
        {
            lb = mid+1;
        }else{
            ub = mid-1;
        }
    }
    if (f==1)
    {
        printf("%d element is found at index position %d",item,mid);
    }else{
        printf("element not found !!");
    }
    getch();
    return 0;
}