#include <stdio.h>
#include <string.h>


void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}


void generatePermutations(char* str, int start, int end) {
    // Base case: If start index is equal to end, print the current permutation
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    // Generate permutations by swapping each character
    for (int i = start; i <= end; i++) {
        // Swap the current character with the start character
        swap(&str[start], &str[i]);

        // Recur for the remaining substring
        generatePermutations(str, start + 1, end);

        // Backtrack to restore the original string
        swap(&str[start], &str[i]);
    }
}

int main() {
    char str[] = "ABC"; // Example input
    int n = strlen(str);

    printf("Permutations of %s:\n", str);
    generatePermutations(str, 0, n - 1);

    return 0;
}
