#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, digit;

        int a = 0, count = 0;
        int arr[10000];

        scanf("%d", &n); // Reading the number

        int original_n = n;

        while (n != 0)
        {
            digit = n % 10;
            arr[a++] = digit; // Store the digit in the array
            n = n / 10;       // Remove the last digit
        }

        for (int i = 0, k = 1; i < a; i++, k *= 10)
        {
            if (arr[i] != 0)
            {
                arr[count++] = arr[i] * k; // Multiply non-zero digits by positional value
            }
        }

        printf("%d\n", count);

        for (int i = 0; i < count; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
