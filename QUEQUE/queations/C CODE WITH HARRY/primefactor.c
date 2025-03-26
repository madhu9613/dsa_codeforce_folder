#include <stdio.h>

long long int primefactor(long long int n)
{
    while (n%2==0)
    {
        printf("%d ",2);
        n/=2;
        /* code */
    }
    for(int i=3;i*i<=n;i=i+2)
    {
        while(n%i==0)
        {
            printf("%d ",i);
            n/=i;
        }

    }
    if(n>2)
    {
        printf("%d",n);
    }
}
int main(){
    long long int n;
scanf("%lld",&n);
printf("the primefactor of %lld are :>",n);
primefactor(n);

    return 0;
}