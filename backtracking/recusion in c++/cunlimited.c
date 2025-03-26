#include <stdio.h>

int main()
{
    int arr[100];
    int index = 0;
    int num;
    char comma;

    printf("Enter numbers separated by commas: ");

    while (scanf("%d%c", &num, &comma) == 2)
    {
        arr[index++] = num;
        if (comma != ',')
        {
            break;
        }
    }

    // Display the numbers stored in the array
    printf("Numbers in the array: ");
    for (int i = 0; i < index; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
