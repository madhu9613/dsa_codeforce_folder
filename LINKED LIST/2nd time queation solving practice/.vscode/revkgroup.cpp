#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Fix: Pass head as a reference to correctly update it.
void insert(int data, node *&head)
{
    node *newNode = new node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Fix: Recursive call should use "forward" instead of "head"
node *reversekgroup(int k, node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    
    // Reverse first k nodes
    int count = 0;
    node *prev = nullptr;
    node *current = head;
    node *forward = nullptr;
    
    while (count < k && current != nullptr)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
        count++;
    }
    
    if (forward != nullptr)
    {
        head->next = reversekgroup(k, forward);
    }
    
    return prev; 
}

// ---with a little bit of modification with if nodes are less than k donot do it:

// Function to check if there are at least k nodes left
bool hasKNodes(node* head, int k) {
    int count = 0;
    while (head && count < k) {
        head = head->next;
        count++;
    }
    return count == k;
}

node* reverse_k_group(int k, node* head) {
    if (head == nullptr || !hasKNodes(head, k)) {
        return head;  // Return head if there are fewer than k nodes left
    }

    node* prev = nullptr;
    node* current = head;
    node* forward = nullptr;
    int count = 0;

    while (count < k && current != nullptr) {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
        count++;
    }

    if (forward != nullptr) {
        head->next = reversekgroup(k, forward);
    }

    return prev;  
}


int main()
{
    int n, k;
    cin >> n >> k;
    
    node *head = nullptr;
    int e;
    
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        insert(e, head);
    }
    
    cout << "Original list is:\n";
    print(head);
    
    head = reversekgroup(k, head);
    
    cout << "Printing in k reverse order:\n";
    print(head);

    return 0;
}
