#include <stdio.h>
int max(int a, int b)

{

    if(a<0)
    {
        a=-1*a;
    }
    if(b<0)
    {
        b=-1*b;
    }
    return a>b?a:b;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++)
{
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int d1 = i - (n - 1);
            int d2 = j - (n - 1);
            int num = max(d1, d2) + 1;
            printf("%d ",num);
        }
        printf("\n");
}
    return 0;
}