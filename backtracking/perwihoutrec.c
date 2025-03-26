#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to swap two characters
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse a substring
void reverse(char* str, int start, int end) {
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

// Function to generate the next lexicographic permutation
bool nextPermutation(char* str, int n) {
    int k = -1;

    // Step 1: Find the rightmost character smaller than the next
    for (int i = n - 2; i >= 0; i--) {
        if (str[i] < str[i + 1]) {
            k = i;
            break;
        }
    }

    // If no such character exists, we're at the last permutation
    if (k == -1) {
        return false;
    }

    // Step 2: Find the rightmost character larger than str[k]
    int l = -1;
    for (int i = n - 1; i > k; i--) {
        if (str[i] > str[k]) {
            l = i;
            break;
        }
    }

    // Step 3: Swap str[k] and str[l]
    swap(&str[k], &str[l]);

    // Step 4: Reverse the substring after index k
    reverse(str, k + 1, n - 1);

    return true;
}

int main() {
    char str[] = "abc"; // Example input
    int n = strlen(str);

    // Step 0: Sort the string to start with the smallest lexicographic permutation
    printf("Permutations:\n");
    do {
        printf("%s\n", str);
    } while (nextPermutation(str, n));

    return 0;
}
