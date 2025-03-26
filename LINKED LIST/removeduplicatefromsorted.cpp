#include <iostream>
#include <sstream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a new node at the end of the linked list
void insert(node* &head, int d) {
    node* newnode = new node(d);
    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to print the linked list
void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to remove duplicates from a sorted linked list
node* deleteduplicatesorted(node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* curr = head;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;  // Free the memory of the duplicate node
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    node* head = nullptr;
    string input;
    cout << "Enter the data: ";
    getline(cin, input);

    stringstream ss(input);
    int data;
    while (ss >> data) {
        insert(head, data);
    }

    cout << "Original linked list: ";
    print(head);

    head = deleteduplicatesorted(head);

    cout << "After deleting duplicates: ";
    print(head);

    return 0;
}
