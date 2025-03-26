#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        // for leading spaces:
        for (int j = i; j <= n; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf(" ");
        }
        
        
           printf("*\n");
        
    }
    return 0;
}