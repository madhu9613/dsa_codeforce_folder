#include <stdio.h>

void findTwoUniqueNumbers(int nums[], int n) {
    int xorAll = 0;

    // Step 1: XOR all elements
    for (int i = 0; i < n; i++) {
        xorAll ^= nums[i];
    }

    // Step 2: Find the rightmost set bit
    int rightmostSetBit = xorAll & -xorAll;

    int num1 = 0, num2 = 0;

    // Step 3: Partition the array into two groups and XOR
    for (int i = 0; i < n; i++) {
        if (nums[i] & rightmostSetBit) {
            num1 ^= nums[i]; // XOR for group 1
        } else {
            num2 ^= nums[i]; // XOR for group 2
        }
    }

    printf("Unique Numbers: %d, %d\n", num1, num2);
}

int main() {
    int nums[] = {1, 2, 3, 2, 1, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    findTwoUniqueNumbers(nums, n);
    return 0;
}
