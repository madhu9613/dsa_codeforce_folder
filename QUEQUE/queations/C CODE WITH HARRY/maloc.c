#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // Dynamically allocate memory for 5 integers
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program if memory allocation fails
    }

    // Get input from the user
    for (int i = 0; i < n; i++) {
        printf("Enter the element no %d: ", i + 1);
        scanf("%d", arr+i);  // Use &arr[i] to pass the address
    }

    // Optionally, print the elements to verify
    printf("The elements in the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
