



#include <stdio.h>
int main() {
    int rows, i, j, k;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Upper half
    for (i = rows; i >= 1; i--) {
        for (j = i; j<=rows; j++) {
            printf("  ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    // Lower half
    for (i = 2; i <= rows; i++) {
        for (j = i; j<=rows; j++) {
            printf("  ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

































