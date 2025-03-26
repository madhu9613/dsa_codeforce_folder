#include <stdio.h>
int main()
{
    int n, a, b, c;
    printf("enter no of rows ");
    scanf("%d", &n);
    a = (n + 1) / 2;
    c = n - 2;
    b = a;
    for (int i = 1; i >= a; i++)
    {
        for (int j = a; j >= b; j--)
        {
            printf("%d ", j);
        }
        for (int k = 1; k <= c; k++)
        {
            printf("%d ", b);
        }
        for (int m = b + 1; m <= a; b++)
        {
            printf("%d ", m);
        }
        b--;
        c = c - 2;

        printf("\n");
    }
    return 0;
}