#include<stdio.h>
#define size 5
int main()
{
    int a[size],i,j,k;
    printf("enter element in an array : ");
    for (i = 0; i < size; i++)
        scanf("%d",&a[i]);

    // for (i = 0; i < size; i++)
    // {
    //     printf("%d",a[i]);
    // }
    
    
    for ( i = 1; i < size; i++)
    {
        k= a[i];
        for ( j = i-1; j >= 0 && k<a[j]; j--)
            a[j+1] = a[j];
        a[j+1] = k;
        
    }
    printf("sorted elements are : ");
    for ( i = 0; i <size; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}