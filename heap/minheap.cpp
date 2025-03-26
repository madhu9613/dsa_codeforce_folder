/*
follow zero based indexing in an arrey an create minimum heap
in zero based index leftchild=2*i+1
                    rightchild=2*i+2;

*/
#include <iostream>
#include <vector>
using namespace std;

// Minimum heapify for zero-based indexing
void heapify(vector<int> &arr, int size, int i) {
    int smallest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    // Compare left child
    if (leftchild < size && arr[leftchild] < arr[smallest]) {
        smallest = leftchild;
    }
    // Compare right child
    if (rightchild < size && arr[rightchild] < arr[smallest]) {
        smallest = rightchild;
    }

    // If the smallest is not the root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        // Recursively heapify the affected subtree
        heapify(arr, size, smallest);
    }
}

// Print the heap
void print(const vector<int> &arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n; // Input the number of elements
    vector<int> arr(n);

    // Input elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the heap (starting from the last non-leaf node)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // After converting to minimum heap
    print(arr, n);

    return 0;
}
