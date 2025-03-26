#include <stdio.h>


void generateSubsets(int nums[], int n, int index, int current[], int currentSize) {
    
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < currentSize; i++) {
            printf("%d ", current[i]);
        }
        printf("}\n");
        return;
    }


    // Exclude the current element and recurse
    generateSubsets(nums, n, index + 1, current, currentSize);

    // Include the current element and recurse
    current[currentSize] = nums[index];
    generateSubsets(nums, n, index + 1, current, currentSize + 1);
    
}

int main() {
    int nums[] = {2, 1, 3}; // Example input
    int n = sizeof(nums) / sizeof(nums[0]);
    int current[100]; // Array to store the current subset (arbitrary size)

    printf("Subsets:\n");
    generateSubsets(nums, n, 0, current, 0);

    return 0;
}
