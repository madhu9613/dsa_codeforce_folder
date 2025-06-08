#include <bits/stdc++.h>
using namespace std;

vector<int> mergearrey(vector<int> a, vector<int> b) {
    vector<int> mr;
    for (int i = 0; i < a.size(); i++) {
        mr.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        mr.push_back(b[i]);
    }
    return mr;
}

// Zero-based indexing heapify function
void heapify(vector<int>& arr, int size, int i) {
    int largest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < size && arr[largest] < arr[leftchild]) {
        largest = leftchild;
    }
    if (rightchild < size && arr[largest] < arr[rightchild]) {
        largest = rightchild;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

int main() {
    vector<int> a, b;
    string input1, input2;

    cout << "Enter data 1: ";
    getline(cin, input1);
    stringstream ss(input1);
    int data;
    while (ss >> data) {
        a.push_back(data);
    }

    cout << "Enter data 2: ";
    getline(cin, input2);
    stringstream ss1(input2);
    while (ss1 >> data) {
        b.push_back(data);
    }

    // Merge two arrays
    vector<int> mr = mergearrey(a, b);

    // Convert merged array into a max-heap
    int n = mr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(mr, n, i);
    }

    // Print the resulting heap
    cout << "Merged Max-Heap: ";
    for (auto i : mr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
