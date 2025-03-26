#include <stdio.h>

int main()
{
    int n,a,k,I,res;
    n=5;
    k=3;
    I=3;
    int sum1=0;
    int sum2=0;
    for(int i=k;i<k+I;i++)
    {
        sum1+=i;
    }
    for(int j=0;j<n-I;j++)
    {
        a=k+I;
        a++;
        sum2+=a;
    }
res=sum2-sum1;
printf("%d\n", sum1);
printf("%d\n",sum2);
printf("%d",res);
}