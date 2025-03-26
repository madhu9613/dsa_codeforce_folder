#include <stdio.h>

void removeLargestAndSmallest(int arr[], int *size) {
    if (*size < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }

    int largest = arr[0];
    int smallest = arr[0];

    // Find largest and smallest elements
    for (int i = 1; i < *size; i++) {
        if (arr[i] > largest) largest = arr[i];
        if (arr[i] < smallest) smallest = arr[i];
    }

    // Remove largest and smallest elements
    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] != largest && arr[i] != smallest) {
            arr[newSize] = arr[i];
            newSize ++;
        }
    }

    *size = newSize; // Update the size of the array
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 9, 1, 4, 7, 2, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    removeLargestAndSmallest(arr, &size);

    printf("Updated array: ");
    printArray(arr, size);

    return 0;
}
