#include <iostream>
#include <sstream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

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

    void createLoop(int position) {
        if (head == nullptr || position <= 0) return;

        Node* temp = head;
        Node* loopNode = nullptr;
        int count = 1;

        while (temp->next != nullptr) {
            if (count == position) {
                loopNode = temp; // Save the node where the loop starts
            }
            temp = temp->next;
            count++;
        }

        // If position is valid, create a loop
        if (loopNode != nullptr) {
            temp->next = loopNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void printLoop(Node* meetNode) {
        Node* temp = meetNode;
        do {
            cout << temp->data;
            if (temp->next != meetNode) {
                cout << " -> ";
            }
            temp = temp->next;
        } while (temp != meetNode);
        cout << " (Loop starts again here)" << endl;
    }

    Node* findStartingPointOfLoop(Node* meetNode) {
        Node* start = head;
        Node* temp = meetNode;

        while (start != temp) {
            start = start->next;
            temp = temp->next;
        }
        return start; // The starting point of the loop
    }

    void removeLoop(Node* loopStart) {
        Node* temp = loopStart;

        // Traverse the loop to find the last node
        while (temp->next != loopStart) {
            temp = temp->next;
        }

        // Set the next of the last node to nullptr to remove the loop
        temp->next = nullptr;
        cout << "Loop removed." << endl;
    }

    void detectAndRemoveLoop() {
        if (head == nullptr) return;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {  // Added proper null checks
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, there is a loop
            if (slow == fast) {
                cout << "Loop detected!" << endl;
                
                
                // Find and print the starting point of the loop
                Node* loopStart = findStartingPointOfLoop(slow);
                cout << "Starting point of the loop: " << loopStart->data << endl;
                printLoop(loopStart);

                // Remove the loop
                removeLoop(loopStart);
                return;
            }
        }

        cout << "No loop found." << endl;
    }
};

int main() {
    LinkedList list;
    string input;

    cout << "Enter elements for the linked list (space-separated): ";
    getline(cin, input); 
    stringstream ss(input);
    int data;
    while (ss >> data) {
        list.insert(data);
    }
system("cls");
    cout << "Linked List: " << endl;
    list.printList();

    int position;
    cout << "Enter the position where you want to create a loop (0 for no loop): ";
    cin >> position;

    list.createLoop(position);
    list.detectAndRemoveLoop();

    
    cout << "Linked List after loop removal: " << endl;
    list.printList();

    return 0;
}
