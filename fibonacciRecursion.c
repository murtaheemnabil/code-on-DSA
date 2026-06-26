#include<stdio.h>
void fibonacci(int n,int x,int y)
{
    if(n<=0)
return;
printf("%d ",x);
fibonacci(n-1,y,x+y);
}
void main()
{
    int n;
    printf("enter no. of terms:");
    scanf("%d",&n);
    fibonacci(n,0,1);
}
