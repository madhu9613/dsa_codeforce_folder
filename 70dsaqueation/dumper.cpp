#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

class nstack {
    int *arr;   
    int *top;   
    int *next;  
    int n, s;   
    int freespot; 

public:
    nstack(int n, int s) {
        this->n = n; 
        this->s = s; 

        arr = new int[s];
        top = new int[n];  
        next = new int[s]; 

        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1;  
        }
        next[s - 1] = -1;  

        freespot = 0;
    }

    void push(int x, int m) {
        if (freespot == -1) {
            cout << "Stack overflow" << endl;
            return;
        }

        int index = freespot;
        freespot = next[index];

        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
    }

    int pop(int m) {
        if (top[m - 1] == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }

        int index = top[m - 1];
        top[m - 1] = next[index];

        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    void insertatbottom(int x, int m) {
        if (top[m - 1] == -1) {
            push(x, m);
            return;
        }

        int temp = pop(m);
        insertatbottom(x, m);
        push(temp, m);
    }

    int delete_middle_from_mth(int m) {
        int count = 0;
        int index = top[m - 1];

        if (index == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        // Count the number of elements in the mth stack
        while (index != -1) {
            count++;
            index = next[index];
        }

        int middle = count / 2 + 1; 
        int removed_value = -1;
        delete_middle_helper(m, middle, removed_value);
        return removed_value;
    }

    void delete_middle_helper(int m, int middle, int &removed_value) {
        if (middle == 1) {
            removed_value = pop(m);
            return;
        }

        int temp = pop(m);
        delete_middle_helper(m, middle - 1, removed_value);
        push(temp, m);
    }

    int get_min_from_mthstack(int m) {
        if (top[m - 1] == -1) {
            cout << "Stack is empty" << endl;
            return INT_MAX;
        }

        int index = top[m - 1];
        int min_val = arr[index];

        while (index != -1) {
            if (arr[index] < min_val)
                min_val = arr[index];
            index = next[index];
        }
        return min_val;
    }
};


int main() {
    int n, s, q;
    cout << "Enter the number of stacks: ";
    cin >> n;
    cout << "Enter the size of the array: ";
    cin >> s;
    nstack stacks(n, s);

    cout << "Enter the number of queries: ";
    cin >> q;

    while (q--) {
        int choice;
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Insert at Bottom\n4. Delete Middle\n5. Get Minimum\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x, m;
                cout << "Enter value and stack number: ";
                cin >> x >> m;
                stacks.push(x, m);
                break;
            }
            case 2: {
                int m;
                cout << "Enter stack number: ";
                cin >> m;
                int popped = stacks.pop(m);
                if (popped != -1)
                    cout << "Popped: " << popped << endl;
                break;
            }
            case 3: {
                int x, m;
                cout << "Enter value and stack number: ";
                cin >> x >> m;
                stacks.insertatbottom(x, m);
                break;
            }
            case 4: {
                int m;
                cout << "Enter stack number: ";
                cin >> m;
                int removed = stacks.delete_middle_from_mth(m);
                if (removed != -1)
                    cout << "Deleted middle element: " << removed << endl;
                break;
            }
            case 5: {
                int m;
                cout << "Enter stack number: ";
                cin >> m;
                int min_val = stacks.get_min_from_mthstack(m);
                if (min_val != INT_MAX)
                    cout << "Minimum element: " << min_val << endl;
                break;
            }
            case 6:
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
    return 0;
}