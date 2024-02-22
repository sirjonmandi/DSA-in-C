#include<stdio.h>
# define size 9
int main()
{
    int a[size],i,j,min,t;
    printf("enter value in an array :");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 0; i < size-1; i++)
    {
        min = i;
        for ( j = i+1; j < size ; j++)
        {
           if (a[min]>a[j])
           {
            min = j;
           }
        }
           if (i != min)
           {
            t = a[i];
            a[i] = a[min];
            a[min] = t;
           }
        
    }
    printf("\n sorted elements : \n");
    for ( i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    return 0 ;
}