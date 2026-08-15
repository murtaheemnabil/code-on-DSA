#include<stdio.h>
int BruteForce(char s[],char p[])
{
    int i,j,ls=0,lp=0;
    while(s[ls]!='\0')
    {
        ls++;
    }
    while(p[lp]!='\0')
    {
        lp++;
    }
    int max=ls-lp+1;
    for(i=1;i<=max;i++)
    {
        int flag=1;
    for(j=1;j<=lp && flag==1;j++)
    {
        if(p[j-1]!=s[j+i-2])
        {
            flag=0;
    }
    }
    if(flag==1)
    {
        return i;
    }
}
return 0;
}
void main()
{
    char s[50],p[50];
    printf("main string:");
    scanf("%s", s);
      printf("pattern string:");
    scanf("%s", p);
    int result=BruteForce(s,p);
    if(result!=0){
        printf("Pattern found at position %d",result);
    }
    else{
        printf("not found");
}
}


