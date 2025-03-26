#include <iostream>
#include <vector>
using namespace std;

class nstack {
    int *arr;   // Main array to store stack elements
    int *top;   // Array to store indexes of the top elements of each stack
    int *next;  // Array to store the next available free index or the next element in the stack
    int n, s;   // n: number of stacks, s: size of the array
    int freespot; // Index of the first free spot in the array

public:
    nstack(int n, int s) {
        this->n = n; 
        this->s = s;
        arr = new int[s];
        top = new int[n]; 
        next = new int[s];

for(int i=0;i<s;i++)
{
    arr[i]=0;
}
        // Initialize all stacks as empty (top = -1 for each stack)
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize all indices in the next array to form a free list
        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1;
        }
        next[s - 1] = -1; // -1 indicates the end of the free list

        freespot = 0; // Initially, the first free spot is 0
    }

    // Push operation
    void push(int x, int m) {
        if (freespot == -1) {
            cout << "Stack overflow\n";
            return;
        }

        // Get the first free spot
        int index = freespot;

        // Update the free spot to the next available one
        freespot = next[index];

        // Insert the element into the array
        arr[index] = x;

        // Update the next array to point to the previous top of stack m
        next[index] = top[m - 1];

        // Update top to the new element
        top[m - 1] = index;

        // Show the state after push
        displayState();


    }

    // Pop operation
    void pop(int m) {
        if (top[m - 1] == -1) {
            cout << "Stack underflow\n";
            return;
        }

        // Get the index of the top element of stack m
        int index = top[m - 1];

        // Update top to the next element in the stack
        top[m - 1] = next[index];

        // Add the popped index to the free list
        next[index] = freespot;
        freespot = index;

        cout << "Popped element: " << arr[index] << endl;

        // Show the state after pop
        displayState();
    }

    // Display the current state of arr, top, and next arrays
    void displayState() {
        cout << "\nArray (arr): ";
        for (int i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }

        cout << "\nTop (top): ";
        for (int i = 0; i < n; i++) {
            cout << top[i] << " ";
        }

        cout << "\nNext (next): ";
        for (int i = 0; i < s; i++) {
            cout << next[i] << " ";
        }

        cout << "\nFreespot: " << freespot << endl;
    }
};

int main() {
    int n, s, queries;

    cout << "Enter the number of stacks: ";
    cin >> n;
    cout << "Enter the size of the array: ";
    cin >> s;

    // Create a multi-stack object
    nstack stacks(n, s);

    cout << "Enter the number of queries: ";
    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cout << "\nEnter query (1 to push, 2 to pop): ";
        int type;
        cin >> type;

        if (type == 1) {
            int value, stack_num;
            cout << "Enter value to push and stack number: ";
            cin >> value >> stack_num;
            stacks.push(value, stack_num);
        } 
        else if (type == 2) {
            int stack_num;
            cout << "Enter stack number to pop from: ";
            cin >> stack_num;
            stacks.pop(stack_num);
        } 
        else {
            cout << "Invalid query type\n";
        }
    }

    return 0;
}
