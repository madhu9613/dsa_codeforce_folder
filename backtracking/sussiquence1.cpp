#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateSubsequences(string str, string output, int index, vector<string>& ans) {
    // Base case: If index is out of bounds, store the current subsequence
    if (index >= str.length()) {
        ans.push_back(output);
        return;
    }

    // Exclude the current character
    generateSubsequences(str, output, index + 1, ans);

    // Include the current character
    output.push_back(str[index]);
    generateSubsequences(str, output, index + 1, ans);

    // output.pop_back(); we have to use back tracking if output is passed by reference because it will contain it
    
}

int main() {
    string str = "abc"; // Example input
    vector<string> ans;
    string output = "";
    int index = 0;

    generateSubsequences(str, output, index, ans);

    // Print all subsequences
    cout << "Subsequences:" << endl;
    for (const string& subsequence : ans) {
        cout << "\"" << subsequence << "\"" << endl;
    }

    return 0;
}
