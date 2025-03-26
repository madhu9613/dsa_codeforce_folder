#include<iostream>
using namespace std;

class Stack {
    int* arr;
    int size;
    int top1;
    int top2;

public:
    // Constructor to initialize two stacks in one array
    Stack(int s) {
        this->size = s;
        arr = new int[size];  // Dynamically allocate memory
        top1 = -1;
        top2 = s;
    }

    // Function to push element in first stack
    void push1(int num1) {
        if (top2 - top1 > 1) {
            arr[++top1] = num1;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    // Function to push element in second stack
    void push2(int num2) {
        if (top2 - top1 > 1) {
            arr[--top2] = num2;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    // Function to pop element from first stack
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack Underflow in Stack 1\n";
            return -1;
        }
    }

    // Function to pop element from second stack
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack Underflow in Stack 2\n";
            return -1;
        }
    }
   void printArray() {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        if (i <= top1 || i >= top2) {
            cout << arr[i] << " ";
        } else {
            cout << "_ ";  // Empty slots between the two stacks
        }
    }
    cout << endl;
}

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int s, q;
    cin >> s >> q;  
    Stack st(s);

    for (int i = 0; i < q; i++) {
        int t, stn, element;
        cin >> t;

        if (t == 1) {  // Push operation
            cin >> stn >> element;
            if (stn == 1) {
                st.push1(element);
            } else {
                st.push2(element);
            }
           st.printArray();
        } 

        
        else if (t == 2) {  // Pop operation
            cin >> stn;
            if (stn == 1) {
                cout << st.pop1() << endl;
                st.printArray();
            } else {
                cout << st.pop2() << endl;
                st.printArray();
            }
        }
    }
st.printArray();
    return 0;
}
