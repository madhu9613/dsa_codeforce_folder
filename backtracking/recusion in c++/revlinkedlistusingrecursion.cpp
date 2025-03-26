#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a new node
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtEnd(Node *&head, Node *&tail, int d)
{
    if (head == nullptr)
    {
        Node *newNode = new Node(d);
        tail = head = newNode;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void reverse(Node *&head, Node *prev, Node *curr)
{
    if (curr == nullptr)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;   // Store the next node
    reverse(head, curr, forward); // Recursive call with current as prev, and next as curr
    curr->next = prev;            // Reverse the link
}

Node *reverseLinkedList(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    reverse(head, prev, curr);
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the linked list:\n";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;
    int e;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        insertAtEnd(head, tail, e);
    }

    cout << "Original list:\n";
    print(head);

    head = reverseLinkedList(head);

    cout << "Reversed list:\n";
    print(head);

    return 0;
}
