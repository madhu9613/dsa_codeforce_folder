#include<stdio.h>
#include<math.h>
int maxpower(int n,int k)
{
int x=0;
while(n-pow(k,x)>=0)
{
    x++;
}
return x-1;
}
int count(int n,int k)
{
   int step=0;
    while(n!=0)
    {
        int a=maxpower(n,k);
    
       n=n-pow(k,a);
       step++;
    }
    
   return step;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int counts=count(n,k);
        printf("%d\n",counts);

    }
    return 0;
}