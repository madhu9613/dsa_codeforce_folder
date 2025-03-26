#include <iostream>
#include <vector>
using namespace std;

class heapnode {
public:
    int data;       // Value of the element
    int arreyindex; // Index of the array
    int elementindex; // Index of the element within the array

    heapnode(int data, int row, int col) {
        this->data = data;
        this->arreyindex = row;
        this->elementindex = col;
    }
};

// Min-Heapify function
void heapify(vector<heapnode> &heap, int n, int i) {
    int smallest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if (lchild < n && heap[lchild].data < heap[smallest].data) {
        smallest = lchild;
    }
    if (rchild < n && heap[rchild].data < heap[smallest].data) {
        smallest = rchild;
    }
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Remove the root element from the heap
void remove(vector<heapnode> &heap, int &size) {
    if (size == 0) {
        return;
    }
    if (size == 1) {
        size--;
        return;
    }
    heap[0] = heap[size - 1]; // Replace the root with the last element
    size--;                   // Decrease the size of the heap
    heapify(heap, size, 0);   // Heapify the root
}

// Function to merge k sorted arrays
vector<int> mergekarrey(vector<vector<int>> &karrey, int k) {
    vector<heapnode> heap;
    vector<int> merged;
    int heapSize = 0;

    // Push the first element of each array into the heap
    for (int i = 0; i < k; i++) {
        if (!karrey[i].empty()) {
            heapnode node(karrey[i][0], i, 0);
            heap.push_back(node);
            heapSize++;
        }
    }

    // Build the initial heap
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, heapSize, i);
    }

    // Process the heap and merge arrays
    while (heapSize > 0) {
        // Get the smallest element (root of the heap)
        heapnode smallest = heap[0];
        merged.push_back(smallest.data);

        // Find the array and element indices
        int arreyIndex = smallest.arreyindex;
        int elementIndex = smallest.elementindex;

        // Replace the root with the next element in the same array
        if (elementIndex + 1 < karrey[arreyIndex].size()) {
            heap[0] = heapnode(karrey[arreyIndex][elementIndex + 1], arreyIndex, elementIndex + 1);
        } else {
            // If the array is exhausted, remove the root
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }

        // Heapify the root
        heapify(heap, heapSize, 0);
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
    vector<int> result = mergekarrey(arrays, k);

    // Output the merged sorted array
    cout << "Merged sorted array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
