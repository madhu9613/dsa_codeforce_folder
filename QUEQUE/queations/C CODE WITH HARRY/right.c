
/*

    *
   **
  ***
 ****
*/
#include<stdio.h>
int main()
{
    int n;
do
{
 scanf("%d",&n);
} while (n<0);
    

    for(int i=0;i<n;i++)
    {
        for(int space=i;space<n;space++)
        {
            printf(" ");
        }
        for(int j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
     for(int i=n-1;i>0;i--)
    {
        for(int space=i;space<n;space++)
        {
            printf(" ");
        }
        for(int j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}