#include <stdio.h>

int main() {
    // Create a string using double quotes
    char my_string[] = "Hello, World!";

    // Loop through each character in the string
    for (int i = 0; my_string[i] != '\0'; i++) {
        printf("%c\n", my_string[i]);
    }
//loop will run till a null character is found

    return 0;
}
