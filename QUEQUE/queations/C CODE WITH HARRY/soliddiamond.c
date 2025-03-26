//now printing complete diamond not hollow
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    //uppper half
    for (int i = 1; i <= n; i++)
    {
        //for leading spaces:
        for (int j = i; j <= n; j++)
        {
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
      printf("\n");

    }
    //lower half
     for (int i =n-1; i >= 1; i--)
    {
        //for leading spaces:
        for (int j =i; j <=n; j++)
        {
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
      printf("\n");

    }
    return 0;
}