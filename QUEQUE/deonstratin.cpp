#include <iostream>
#include <sstream>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int size;
public:
    Queue() {
        size = 10; 
        arr = new int[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=0;
        }
        front = rear = 0;
    }

    bool isempty() {
        return front == rear;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full\n";
        } else {
            arr[rear++] = data;
            cout << "Enqueued: " << data << endl;
            printState();
        }
    }

    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            int ans = arr[front];
            arr[front++] = -1;
            if (front == rear) {
                front = rear = 0;
            }
            cout << "Dequeued: " << ans << endl;
            printState();
            return ans;
        }
    }

    void printState() {
        cout << "Queue state: [";
        for (int i = 0; i < size; i++) {
            if (arr[i] != -1) {
                cout << arr[i];
            } else {
                cout << "_";
            }
            if (i < size - 1) cout << ", ";
        }
        cout << "]\n";
        cout << "Front index: " << front << ", Rear index: " << rear << "\n\n";
    }
};

int main() {
    Queue q;
    string command;

    cout << "Enter commands (E <value> for enqueue, D for dequeue, stop to end):\n";

    while (true) {
        getline(cin, command);
        if (command == "stop") {
            break;
        }

        stringstream ss(command);
        string op;
        ss >> op;

        if (op == "E") {
            int value;
            ss >> value;
            q.enqueue(value);
        } else if (op == "D") {
            q.dequeue();
        } else {
            cout << "Invalid command\n";
        }
    }

    cout << "Program ended.\n";
    return 0;
}
