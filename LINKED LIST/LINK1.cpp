#include <iostream>
using namespace std;

class node
{
public:
    int data;   // To store data
    node *next; // Pointer to the next node

    // Constructor to initialize a node
    node(int data)
    {
        this->data = data; // Set node's data
        this->next = NULL; // Initialize next as NULL
    }
};

// Function to insert a new node at the head of the linked list
void insertathead(node *&head, int d)
{
    node *temp = new node(d); // Create a new node
    temp->next = head;        // Point next of new node to the current head
    head = temp;              // Update head to point to the new node
}

// Function to insert a new node at the tail of the linked list
void insertattail(node *&tail, int d)
{
    node *temp = new node(d); // Create a new node
    
                    // If tail is not NULL
        tail->next = temp; // Link the current tail node to the new node

    tail = temp; // Update tail to point to the new node
}

// Function to print the linked list
void print(node *head)
{
    node *temp = head; // Start from the head
    while (temp != NULL)
    {                              // Traverse until the end of the list
        cout << temp->data << " "; // Print node's data
        temp = temp->next;         // Move to the next node
    }
    cout << endl; // Print a new line after printing the entire list
}

int main()
{
    node *head = NULL; // Initialize the head as NULL
    node *tail = NULL; // Initialize the tail as NULL
    int n, data, choice;

    cout << "Number of elements you want to add: ";
    cin >> n; // Get the number of elements to insert

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> data; // Get the data for the new node
        cout << "Insert at head (1) or tail (2)? ";
        cin >> choice; // Ask user where to insert the element

        if (choice == 1)
        {
            insertathead(head, data); // Insert the new node at the head
            if (tail == NULL)
            { // If this is the first element, set tail to head
                tail = head;
            }
        }
        else if (choice == 2)
        {
            if (tail == NULL)
            {                                 // If the list is empty
                head = tail = new node(data); // Initialize both head and tail
            }
            else
            {
                insertattail(tail, data); // Insert the new node at the tail
            }
        }
    }

    cout << "Elements in the linked list (head to tail): " << endl;
    print(head); // Print the linked list from head to tail

    return 0;
}
