#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    vector<int> v;
    vector<int> result;
    stringstream ss(input);
    int data;

  
    while (ss >> data) {
        v.push_back(data);
    }

   
    int maxArea = 0;

    // Brute-force approach to calculate the area for each bar
    for (int i = 0; i < v.size(); i++) {
        int height = v[i];
        int left = i, right = i;
        int width = 1;

        while (left - 1 >= 0 && v[left - 1] >= height) {
            left--;
            width++;
        }

        
        while (right + 1 < v.size() && v[right + 1] >= height) {
            right++;
            width++;
        }

        // Calculate area
        int area = height * width;
        result.push_back(area);  // Store the area in the result vector

        // Update max area
        if (area > maxArea) {
            maxArea = area;
        }
    }

    // Output the area for each bar
    cout << "Area for each bar: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    // Output the maximum area
    cout << "Largest rectangle area: " << maxArea << endl;

    return 0;
}
