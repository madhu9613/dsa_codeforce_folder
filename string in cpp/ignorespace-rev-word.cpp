#include <iostream>
#include <cstring> // For strlen, strcpy, etc.
using namespace std;

void reverse(char* start, char* end) {
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

void reverseWords(char str[]) {
    int n = strlen(str);
    
    reverse(str, str + n - 1);

    
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(str + start, str + i - 1);
            start = i + 1;
        }
    }
}

int main() {
    char input[100];   

    
    cout << "Enter a string: ";
    cin.getline(input, 100); 

    
    reverseWords(input);

    cout << "Reversed words: " << input << endl;

    return 0;
}
