

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr;
    int n;
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("memorry not allocated \n");
        return 1; // exist the program if memory not allocated ;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    printf("entred arrey is :\n ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    // modifying this arrey by using ptr :



    int *ptr;

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("memorry not allocated \n");
        return 1;
    }
    for (int i = 1; i < n; i += 2)
    {
        *(ptr + i) = *(arr + i) * 2;
    }
    for (int i = 0; i < n; i += 2)
    {
        *(ptr + i) = *(arr + i) * 3 + 1;
    }

    // printing ptr;
    printf("modified arrey is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Modify and print the array in a single pass
    printf("Modified array is:\n");
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ptr[i] = arr[i] * 3 + 1;
        } else {
            ptr[i] = arr[i] * 2;
        }
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(arr);
    free(ptr);
    return 0;
}