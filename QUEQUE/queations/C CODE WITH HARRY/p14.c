#include <stdio.h>

int main() {
    int year;
    printf("Enter year: \n");
    scanf("%d", &year);

    if (year % 400 == 0) {
        printf("LEAP YEAR\n");
    } else if (year % 100 == 0) {
        printf("NOT LEAP YEAR\n");
    } else if (year % 4 == 0) {
        printf("LEAP YEAR\n");
    } else {
        printf("NOT LEAP YEAR\n");
    }
    
    return 0;
}
