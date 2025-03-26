#include <iostream>
using namespace std;

int sumArray(int *arr, int n) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return arr[0];
    }
    // Recursive case: first element + sum of remaining array
     int sum=arr[0]+sumArray(arr+1,n-1);
    return sum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = sumArray(arr, n);
    cout << "Sum of the array is: " << sum << endl;

    // Free the allocated memory
    delete[] arr;
    return 0;
}
