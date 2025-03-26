#include<iostream>
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

// Insert at the head of the linked list
void insertathead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

// Insert at the tail of the linked list
void insertattail(node*& tail, int d) {
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}

// Insert at a specific position
void insertatposition(node*& head, node*& tail, int p, int d) {
    if (p == 1) {
        insertathead(head, d);
        if (tail == NULL) {  // Update tail if list was empty
            tail = head;
        }
        return;
    }

    node* temp = head;
    int c = 1;
    while (c < p - 1 && temp != NULL) {
        temp = temp->next;
        c++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (temp->next == NULL) {
        insertattail(tail, d);
        return;
    }

    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}


// Print the linked list
void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    int d, p, n;

    cout << "Enter the number of elements you want to add: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter position (1 to " << i + 1 << "): " << endl;
        cin >> p;
        cout << "Enter element: " << endl;
        cin >> d;
        insertatposition(head, tail, p, d);
        
        // Ensure tail is updated if it's still NULL (first insertion)
        if (tail == NULL) {
            tail = head;
        }
    }

    print(head);

    return 0;
}
