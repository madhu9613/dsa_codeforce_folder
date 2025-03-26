/*

Each character in the string can either:

Be included in the subsequence.
Be excluded from the subsequence.
For a string of length 

  possible combinations of inclusion and exclusion. These 

  combinations can be represented using binary numbers from 0 to 


Each bit (binary digit) in the number corresponds to a character in the string.
If a bit is 1, include the corresponding character in the subsequence.
If a bit is 0, exclude the corresponding character.


*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void generateSubsequences(char str[]) {
    int n = strlen(str);
    int totalSubsequences = pow(2, n); // Total subsequences = 2^n

    printf("Subsequences of the string \"%s\":\n", str);

    for (int i = 0; i < totalSubsequences; i++) {
        printf("\"");
        for (int j = 0; j < n; j++) {
            // Check if the j-th bit in i is set
            if (i & (1 << j)) {
                printf("%c", str[j]);
            }
        }
        printf("\"\n");
    }
}

int main() {
    char str[100]; 

   
    printf("Enter a string: ");
    scanf("%s", str);

    generateSubsequences(str);

    return 0;
}
