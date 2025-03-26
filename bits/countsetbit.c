#include<stdio.h>
#include<stdbool.h>
int countsetbit(int n)
{
     int count = 0;
    while (n) {
        count++;
        n &= (n - 1);  // Remove the rightmost set bit
    }
    return count;
}
bool ispowerof2(int n)
{
    return n>0 && (n&(n-1))==0;
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int ans=countsetbit(n);
    printf("%d\n",ans);
    if(ispowerof2(n))
    {
        printf("%d is power of two \n",n);
       
    }
    else
    {
        printf("not \n");
    }   

    for(int i=0;i<10000;i++)
    {
        if(ispowerof2(i))
        {
            printf("%d ",i);
        };
    }
    return 0;
}