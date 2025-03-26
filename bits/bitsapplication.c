#include<stdio.h>
int main()
{

int a = 5;            // 0101 in binary
int b = 3;            // 0011 in binary
int result1 = a & b;  // 0001 in binary (1 in decimal)

 a = 5;                 // 0101 in binary
 b = 3;                 // 0011 in binary
 int result2 = a | b;   // 0111 in binary (7 in decimal)

 a = 5;                  // 0101 in binary
 b = 3;                  // 0011 in binary
int result3 = a ^ b;     // 0110 in binary (6 in decimal)

//left shift means multiply by 2


 a = 5;                  // 0101 in binary
 int result4 = a << 1;   // 1010 in binary (10 in decimal)


//right shift means divided  by 2

      a = 5;              // 0101 in binary
int result5 = a >> 1;     // 0010 in binary (2 in decimal)


// setting a bit
    a = 5;          // 0101 in binary
a = a | (1 << 1);   // Set the second bit (from the right) to 1 -> 0111 (7)

//clearing a bit
  int a = 5;         // 0101 in binary
a = a & ~(1 << 1);   // Clear the second bit -> 0001 (1)

//toggling A BIT  
int a = 5;         // 0101 in binary
a = a ^ (1 << 1);  // Toggle the second bit -> 0001 (1)

//checking if a bit is set
int a = 5;                        // 0101 in binary
int isSet = (a & (1 << 1)) != 0;  // Check if the second bit is set -> 1 (true)


    return 0;
}
