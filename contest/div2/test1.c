#include<stdio.h>
int main()
{
    int i,n,t;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n%2==0)
          printf("Sakurako\n");
        else
          printf("Kosuke\n");


    }
    

    return 0;
}