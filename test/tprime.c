#include <stdio.h>
#include <stdlib.h>
int istprime(int n)
{
    int fac[n];
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            fac[count++] = i;
        }
    }
    if (count == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    return 0;
}