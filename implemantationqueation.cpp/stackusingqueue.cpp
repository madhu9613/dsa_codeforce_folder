#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1; // Main queue
    queue<int> q2; // Helper queue

public:
    // Push an element onto the stack
    void push(int x) {
        // Push the new element into q2
        q2.push(x);

        // Push all the elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        swap(q1, q2);
    }

    // Pop the top element from the stack
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    // Get the top element of the stack
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        throw runtime_error("Stack is empty!");
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }

    // Get the size of the stack
    int size() {
        return q1.size();
    }
};

int main() {
    StackUsingQueues stack;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        stack.push(data);
    }
    cout << "Top element: " << stack.top() << endl; // Output: 3
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Output: 2

    return 0;
}
