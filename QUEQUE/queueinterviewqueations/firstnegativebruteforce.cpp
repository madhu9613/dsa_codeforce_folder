/*Given an array arr[]  and a positive integer k, find the first negative integer for 
each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.*/

#include <iostream>
#include <vector>
using namespace std;
void solvebruteforce(vector<int> v,vector<int> &result,int n,int k)
{
 // Traverse through each window of size k
    for (int i = 0; i <= n - k; i++) {
        bool found = false;
        for (int j = i; j < i + k; j++) {
            if (v[j] < 0) { // Check the current element in the window
                result.push_back(v[j]);
                found = true;
                break; // Exit the loop after finding the first negative integer
            }
        }
        if (!found) {
            result.push_back(0); // No negative integer found in the window
        }
    }
}

int main() {
    int n, k;
    vector<int> v;
    cin >> n >> k;
    vector<int> result;
    int data;

    // Input the array
    for (int i = 0; i < n; i++) {
        cin >> data;
        v.push_back(data);
    }

   
// solvebruteforce(v,result,n,k);
    // Output the results
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
