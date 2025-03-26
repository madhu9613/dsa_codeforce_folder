#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    vector<int> result;
    string input;
    
    getline(cin, input);  
    stringstream ss(input);
    
    int element;

    while (ss >> element) {
        v.push_back(element);
    }
    
    
    for (int i = 0; i < v.size(); i++) {
        
        int minVal = -1;
        
       
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[i]) {
                minVal = v[j];  
                break; 
            }
        }
        
      
        result.push_back(minVal);
    }
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
