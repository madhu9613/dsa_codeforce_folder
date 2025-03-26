#include <iostream>
#include <unordered_map>
using namespace std;

void findFrequencyAndUpdate(int arr[][100], int r, int c) {
    unordered_map<int, int> frequencyMap; // To store frequencies
    int maxFreq = 0; // To keep track of maximum frequency
    int maxElement = 0; // To store the element with maximum frequency

    // Calculate frequencies of each element
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            frequencyMap[arr[i][j]]++;

            // Update max frequency and max element
            if (frequencyMap[arr[i][j]] > maxFreq) {
                maxFreq = frequencyMap[arr[i][j]];
                maxElement = arr[i][j];
            }
        }
    }

    // Print frequencies of each element
    cout << "Frequencies of each element:" << endl;
    for (const auto& entry : frequencyMap) {
        cout << "Element " << entry.first << ": " << entry.second << " times" << endl;
    }

    // Update the element with highest frequency
    cout << "Element with highest frequency: " << maxElement << " (Frequency: " << maxFreq << ")" << endl;

    // Update the element in the array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == maxElement) {
                arr[i][j] = (arr[i][j] == 0) ? 1 : 0; // Update to zero or one
            }
        }
    }

    // Print the updated matrix
    cout << "Updated matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r, c;

    cout << "Enter number of rows and columns: " << endl;
    cin >> r >> c;
    int arr[100][100];
    
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    // Find frequency and update matrix
    findFrequencyAndUpdate(arr, r, c);

    return 0;
}
