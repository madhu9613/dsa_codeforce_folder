#include<iostream>
#include<vector>
using namespace std;

class Stack {
    vector<int> arr;  
    int top;

public:
   
    Stack() {
        top = -1;
    }

   
    void push(int element) {
        arr.push_back(element);  
        top++;
        
    }

  
    void pop() {
        if (top >= 0) {
           
            arr.pop_back();  
            top--;
        } else {
            cout << "Stack Underflow!\n";
        }
    }

   
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty\n";
            return -1;
        }
    }

    
    bool empty() {
        return top == -1;
    }

   
    void print() {
        while (!empty()) {
            cout << peek() << " ";
            pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);
    s.print();  

    return 0;
}
