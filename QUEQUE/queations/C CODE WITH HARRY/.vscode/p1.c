
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(0));

    // Generate a random number between 1 and 150
    int randomNumber = (rand() % 150) + 1;
    int gussed;
    // rand() % 150: Generates a random number between 0 and 149.
    // (rand() % 150) + 1: Shifts the range from 0-149 to 1-150 by adding 1

    // Display the random number

    // printf("Random Number (1 to 150): %d\n", randomNumber);
     int no_of_guess =0;

do
{
    printf("guess the number \n");
    scanf("%d \n" , &gussed);
    if (gussed>randomNumber)
    {
        printf("lower number please \n ");
        /* code */
    }
    else if (gussed<randomNumber)
    {
        /* code */
        printf("higher number please \n");
    }
    
    no_of_guess ++;
    /* code */
} while (gussed!=randomNumber);
printf("you gussed the number in %d gusses " , no_of_guess);
    return 0;
}
