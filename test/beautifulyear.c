#include <stdio.h>

int makearrey(int n, int arr[])
{
    int i = 0;
    while (n != 0)
    {
        int digit = n % 10;
        arr[i++] = digit;
        n = n / 10;
    }
    return i;
}

int is_unique(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return 0;  // Digits are not unique
            }
        }
    }
    return 1;  // Digits are unique
}

int has_unique_digits(int n)
{
    int arr[10];
    int size = makearrey(n, arr);
    return is_unique(arr, size);
}

int main()
{
    int year;
    scanf("%d", &year);

    while (1)
    {
        year++;
        if (has_unique_digits(year))
        {
            break;
        }
    }
    printf("%d\n", year);

    return 0;
}
