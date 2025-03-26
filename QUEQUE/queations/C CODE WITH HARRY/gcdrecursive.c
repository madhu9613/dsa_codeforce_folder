#include <stdio.h>
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
   
    else{
    return  gcd(b,a%b);
    }
}
int main(){
    int a,b;
    printf("enter two number >: \n");
    scanf("%d%d",&a,&b);
    int ans=gcd(a,b);
    printf("gcd of %d and %d is :> %d",a,b,ans);
    return 0;
}