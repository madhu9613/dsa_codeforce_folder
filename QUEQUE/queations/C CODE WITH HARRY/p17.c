#include <stdio.h>

int main()
{
    int a, b;
    printf("enter first number : \n");
    scanf("%d",&a);
    printf("enter second number : \n");
    scanf("%d",&b);

    if (a > b)
    {
        int res = a + b;
        printf("%d", res);
    }
    if (b > a)
    {
        int res = a - b;
        printf("%d", res);
    }

    return 0;
}