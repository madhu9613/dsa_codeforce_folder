#include<iostream>
using namespace std;

class nstack {
    int *arr;   // Array to store elements
    int *top;   // Array to store top elements of all stacks
    int *next;  // Array to store next free spot or next element index
    int n, s;   // n = number of stacks, s = size of the array
    int freespot; // To track the free spot

public:
    // Constructor
    nstack(int n, int s) {
        this->n = n; // Number of stacks
        this->s = s; // Size of the array

        // Allocate memory
        arr = new int[s];
        top = new int[n];  // One entry for each stack
        next = new int[s]; // One entry for each element in the array

        // Initialize all stacks' tops to -1 (empty)
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize all spaces in the array as free
        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1;  // Next free spot in the array
        }
        next[s - 1] = -1;  // End of free list

        // Initially, freespot is 0
        freespot = 0;
    }

    // Push operation
    void push(int x, int m) {
        if (freespot == -1) {
            cout << "Stack overflow" << endl;
            return;
        }

        // Find index where to push new element
        int index = freespot;

        // Update freespot to the next available index
        freespot = next[index];

        // Insert element into array
        arr[index] = x;

        // Link the new element to the previous top of stack m
        next[index] = top[m - 1];

        // Update top to the new element
        top[m - 1] = index;
    }

    // Pop operation
    int pop(int m) {
        // Check for stack underflow
        if (top[m - 1] == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }

        // Find the index to pop from
        int index = top[m - 1];

        // Update top to the next element in the stack
        top[m - 1] = next[index];

        // Add the popped index to the free list
        next[index] = freespot;
        freespot = index;

        // Return the popped element
        return arr[index];
    }
};

int main() {
    // Example: 3 stacks and an array of size 10
    nstack stacks(3, 10);

    // Push some elements
    stacks.push(10, 1);
    stacks.push(20, 1);
    stacks.push(30, 2);

    // Pop elements
    cout << "Popped from stack 1: " << stacks.pop(1) << endl; // Output: 20
    cout << "Popped from stack 2: " << stacks.pop(2) << endl; // Output: 30

    return 0;
}
