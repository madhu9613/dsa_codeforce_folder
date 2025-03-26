#include <stdio.h>
int gcdnonr(int a, int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;

    }
    return a;
}
int main(){
    int a,b;
    printf("enter two number >: \n");
    scanf("%d%d",&a,&b);
    int ans=gcdnonr(a,b);
    printf("gcd of a and b is :> %d",ans);
    return 0;
}