#include <stdio.h>
#include <stdlib.h>

int maxelement(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        int l, r;
        char c;
        scanf("%d%d", &n, &m);

        int *arr = (int *)malloc(n * sizeof(int));
        int *res = (int *)malloc(m * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < m; i++)
        {
            scanf(" %c%d%d", &c, &l, &r);
        }

        for (int j = 0; j, n; j++)
        {

            if (arr[j] <= r && arr[j] >= l)
            {
                if (c == '+')
                {

                    arr[j] = arr[j] + 1;
                }
                else if (c == '-')
                {

                    arr[j] = arr[j] - 1;
                }
            }
            // Get the max element after the operation and store in result
            int ans = maxelement(arr, n);
            res[j] = ans;
        }

        // Output the results
        for (int i = 0; i < m; i++)
        {
            printf("%d ", res[i]);
        }
        printf("\n");

        // Free allocated memory
        free(arr);
        free(res);
    }
    return 0;
}

