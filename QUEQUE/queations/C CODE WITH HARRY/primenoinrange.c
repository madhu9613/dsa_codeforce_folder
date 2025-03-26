#include <stdio.h>
#include<stdbool.h>
bool isprime(int n)
{
    if(n==1||n==2||n==3)
    {
        return true;

    }
    for(int i=4;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main(){
    int s,e;
    printf("enter range :eg>(1 100):\n");
    scanf("%d%d",&s,&e);
for(int i=s;i<=e;i++)
{
    if(isprime(i))
    {
        printf("%d  ",i);
    }
}
    return 0;
}