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



Node* reverseLinkedList(Node* &head)
{
    if(head==NULL || head->next==NULL)
    {
    return head;
    }
    Node* reqhead=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=NULL;
    return reqhead;
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
