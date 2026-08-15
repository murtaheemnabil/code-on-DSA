#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    int *ptr;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory allocation failed!");
        return 1;
    }
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("Elements in the array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    free(ptr);
    return 0;
}
