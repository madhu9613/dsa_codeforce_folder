#include <iostream>
#include <algorithm> 
#include <string>   

using namespace std;

void reverse(string& str, int start, int end) {
    while (start < end) {
        swap(str[start], str[end]); 
        start++;
        end--;
    }
}

void reverseWords(string& str) {
    int n = str.length();

    
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(str, start, i - 1);  
            start = i + 1;               
        }
    }
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);  

    reverseWords(input);

    // Output the result
    cout << "Reversed words: " << input << endl;

    return 0;
}
