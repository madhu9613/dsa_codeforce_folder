#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Read the number of test cases
    while (t--) {
        int n;
        cin >> n;  // Length of the array for this test case
        vector<int> a(n);
          vector<int> b;  // Result array
          unordered_map<int, int> freq;  // To store the frequency of elements
        unordered_map<int, int> appeared;  // To store how many times an element appeared in b
        unordered_map<int, bool> addedOnce; // To track if an element was added once before
        for (int i = 0; i < n; ++i) {
            cin >> a[i];  // Read the array a
            freq[a[i]]++;
            if(freq[i]<=2)
           {
            
           }
        }

      
      

        
        // Output the array b
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i] << " ";
        }
        cout<<endl;
    }
}

int main() {
    solve();  // Call the solve function to process all test cases
    return 0;
}
