#include <iostream>
#include <stack>
#include <climits>  // For INT_MAX
using namespace std;

class MinStack {
    stack<int> s;
    int minElement;

public:
    MinStack() {
        minElement = INT_MAX;
    }

    void push(int data) {
        if (s.empty()) {
            minElement = data;
            s.push(data);
        } else {
            if (data < minElement) {
                // Encode previous minElement, then push new minElement
                s.push(2 * data - minElement);
                minElement = data;
            } else {
                s.push(data);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        int top = s.top();
        s.pop();
        if (top < minElement) {
            // Decode previous minElement
            minElement = 2 * minElement - top;
        }
    }

    int top() {
        if (s.empty()) return INT_MAX;
        
        int top = s.top();
        return (top < minElement) ? minElement : top;
    }

    int getMin() {
        if (s.empty()) return INT_MAX;
        return minElement;
    }
};

int main() {
    MinStack ms;
    int n, data;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        ms.push(data);
    }

    cout << "Minimum number in the stack is: " << ms.getMin() << endl;
    return 0;
}
