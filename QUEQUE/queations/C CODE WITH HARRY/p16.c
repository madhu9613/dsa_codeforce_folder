#include <stdio.h>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b)
    {
        printf("%d is bigger :\n",a);
    }
   else if(b>a)
    {
        printf("%d is bigger :\n",b);
    }
    else

    {
        printf("EQUAL\n");
    }

    return 0;
}