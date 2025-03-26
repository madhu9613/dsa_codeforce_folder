#include <stdio.h>
#include <math.h>

void generateSubsets(int nums[], int n) {
    // Total subsets = 2^n (for a set of size n)
    int totalSubsets = pow(2, n);

    // Loop through all possible binary numbers from 0 to (2^n - 1)
    for (int i = 0; i < totalSubsets; i++) {
        printf("{ ");
        
        // For each subset, check the binary representation of i
        for (int j = 0; j < n; j++) {
            // Check if the j-th bit is set in the binary representation of i
            if (i & (1 << j)) {
                printf("%d ", nums[j]);
            }
        }
        
        printf("}\n");
    }
}

int main() {
    int nums[] = {1, 2, 3}; 
    int n = sizeof(nums) / sizeof(nums[0]); 

    printf("Subsets of the set {1, 2, 3} are:\n");
    generateSubsets(nums, n);

    return 0;
}
