#include <iostream>
#include <stack>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    stack<char> s;
    int a = 0, b = 0;

    // Count opening and unmatched closing braces
    for (char c : input) {
        if (c == '{') {
            s.push(c);
            a++;
        } else if (c == '}') {
            if (!s.empty() && s.top() == '{') {
                s.pop();
                a--;
            } else {
                b++;
            }
        }
    }

    int n = a + b;

    // Handling various cases
    if (n % 2 != 0) {
        cout << -1 << endl; // Total unmatched braces are odd
    } else {
        // Minimum operations to balance
        cout << (a + 1) / 2 + (b + 1) / 2 << endl;
    }

    return 0;
}
