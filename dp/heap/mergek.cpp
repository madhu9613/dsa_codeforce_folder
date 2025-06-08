#include <bits/stdc++.h>
using namespace std;

// Definition of a heap node
class HeapNode {
public:
    int data;  // Value of the element
    int aidx;  // Index of the array
    int eidx;  // Index of the element in the array

    HeapNode(int data, int aidx, int eidx) {
        this->data = data;
        this->aidx = aidx;
        this->eidx = eidx;
    }
};

// Custom comparator for the min-heap
class Compare {
public:
    bool operator()(HeapNode* a, HeapNode* b) {
        return a->data > b->data; // Min-heap (smallest element has the highest priority)
    }
};

// Function to merge k sorted arrays
vector<int> mergeSortedArrays(vector<vector<int>>& arrays, int k) {
    vector<int> merged;
    priority_queue<HeapNode*, vector<HeapNode*>, Compare> pq;

    // Push the first element of each array into the heap
    for (int i = 0; i < k; i++) {
        if (!arrays[i].empty()) { // Check if the array is not empty
            HeapNode* node = new HeapNode(arrays[i][0], i, 0);
            pq.push(node);
        }
    }

    // Process the heap
    while (!pq.empty()) {
        HeapNode* temp = pq.top();
        pq.pop();

        // Add the smallest element to the result
        merged.push_back(temp->data);

        // Get the array index and element index
        int aidx = temp->aidx;
        int eidx = temp->eidx;

        // If there is a next element in the same array, push it into the heap
        if (eidx + 1 < arrays[aidx].size()) {
            HeapNode* nextNode = new HeapNode(arrays[aidx][eidx + 1], aidx, eidx + 1);
            pq.push(nextNode);
        }

        // Free the memory for the processed node
        delete temp;
    }

    return merged;
}

int main() {
    int k;
    cout << "Enter the number of arrays: ";
    cin >> k;

    vector<vector<int>> arrays(k);

    // Input arrays
    for (int i = 0; i < k; i++) {
        int size;
        cout << "Enter the size of array " << i + 1 << ": ";
        cin >> size;

        arrays[i].resize(size);
        cout << "Enter elements of array " << i + 1 << ": ";
        for (int j = 0; j < size; j++) {
            cin >> arrays[i][j];
        }
    }

    // Merge the arrays
    vector<int> result = mergeSortedArrays(arrays, k);

    // Output the merged sorted array
    cout << "Merged sorted array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
