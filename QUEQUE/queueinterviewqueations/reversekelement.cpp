#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

void reverseFirstKElements(queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        return;  // Handle invalid k values
    }

    stack<int> s;

    // Step 1: Push the first k elements onto the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the stack elements back into the queue (these are now reversed)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the rest of the original elements to the back of the queue to maintain order
    int remainingElements = q.size() - k;
    for (int i = 0; i < remainingElements; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int data;

    // Read input queue elements
    while (ss >> data) {
        q.push(data);
    }

    int k;
    cout << "Enter number of elements to reverse: ";
    cin >> k;

    // Reverse the first k elements
    reverseFirstKElements(q, k);

    cout << "Queue after reversing first " << k << " elements:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
