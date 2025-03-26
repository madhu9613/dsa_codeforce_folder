#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front;
    int rear;
    int size;
public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = data;
        cout << "Enqueued: " << data << endl;
        printState();
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int result = arr[front];
        if (front == rear) {  // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Dequeued: " << result << endl;
        printState();
        return result;
    }

    void printState() {
        cout << "Queue state: [";
        if (!isEmpty()) {
            int i = front;
            while (true) {
                cout << arr[i];
                if (i == rear) break;
                i = (i + 1) % size;
                cout << ", ";
            }
        }
        cout << "]\n";
        cout << "Front index: " << front << ", Rear index: " << rear << "\n\n";
    }
};

int main() {
    CircularQueue q(5);

    // Sample operations
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);  // Queue should be full here
    q.dequeue();
    q.enqueue(7);  // Should wrap around to the front

    return 0;
}
