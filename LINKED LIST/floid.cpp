#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor using 'this'
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr; 
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to create a loop
    void createLoop(int position) {
        if (head == nullptr) return;

        Node* temp = head;
        Node* loopNode = nullptr;
        int count = 1;

        while (temp->next != nullptr) {
            if (count == position) {
                loopNode = temp;  // Save the node at the specified position
            }
            temp = temp->next;
            count++;
        }

        // Create the loop
        if (loopNode != nullptr) {
            temp->next = loopNode;
        }
    }

    // Function to detect if there is a loop in the linked list
    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                printLoop(slow);  // Print the loop starting from the meeting point
                return true;      // Loop detected
            }
        }
        return false;  // No loop detected
    }

    // Function to print the elements of the loop
    void printLoop(Node* meetingPoint) {
        Node* temp = meetingPoint;
        do {
            cout << temp->data << " ";  // Print the data of the node
            temp = temp->next;
        } while (temp != meetingPoint);  // Continue until we come back to the meeting point
        cout << endl;  // Print a new line after printing the loop
    }

    // Destructor to clean up the memory
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    list.createLoop(3);  

    if (list.detectLoop()) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0; 
}
