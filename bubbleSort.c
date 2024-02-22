#include<stdio.h>
#define size 6
int main()
{
    int a[size],i,j,t,c;
    printf("enter values in an array :");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 0; i < size-1; i++)
    {
        c=0;
        for ( j = 0; j < size-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                c++;
            }
            
        }
        if (c==0)
        {
            break;
        }
        
    }
    printf("\n sorted elements : \n");
    for ( i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}