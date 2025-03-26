#include <iostream>
using namespace std;

void store(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binary_search(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;  // Key found, return the index
        } else if (arr[mid] < key) {
            low = mid + 1;  // Search in the right half
        } else {
            high = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Key not found, return -1
}

int main() {
    int n;
    int num[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array in sorted order: ";
    store(num, n);

    cout << "Entered array is: ";
    print(num, n);

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int res = binary_search(num, n, key);

    if (res != -1) {
        cout << "Index of the key is: " << res << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
