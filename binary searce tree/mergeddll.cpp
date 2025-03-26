#include <iostream>
#include <queue>
using namespace std;

// Node definition for Binary Tree and Doubly Linked List
class node {
public:
    int data;
    node *left;
    node *right;

    // Constructor
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a binary tree from level-order input
node* buildtreefromlevelorder() {
    int data;
    cout << "Enter data for root (-1 for NULL): " << endl;
    cin >> data;

    if (data == -1) {
        return nullptr; // No tree to create
    }

    // Create the root node
    node* root = new node(data);
    queue<node*> q;
    q.push(root);

    // Level-order insertion
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        // Input for left child
        cin >> data;
        if (data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }

        // Input for right child
        cin >> data;
        if (data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}

// Convert binary tree to a doubly linked list (DLL) using reverse in-order traversal
void converttodll(node* root, node*& head) {
    if (root == NULL) {
        return;
    }

    // Process right subtree first (reverse in-order)
    converttodll(root->right, head);

    // Link the current root to the head of the DLL
    root->right = head;
    if (head != NULL) {
        head->left = root;
    }

    // Update head to the current root
    head = root;

    // Process left subtree
    converttodll(root->left, head);
}

// Merge two sorted doubly linked lists into one
node* mergetwodll(node* head1, node* head2) {
    node* head = NULL;
    node* tail = NULL;

    // Merge while both lists have nodes
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            // Add head1's node
            if (head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            // Add head2's node
            if (head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    // Add remaining nodes from either list
    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// Count the number of nodes in a DLL
int getnodes(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->right;
    }
    return count;
}

// Convert a sorted DLL to a balanced binary search tree (BST)
node* sortedlltobst(node*& head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    // Construct the left subtree
    node* left = sortedlltobst(head, n / 2);

    // Create the root node
    node* root = head;
    root->left = left;

    // Move to the next node in the DLL
    head = head->right;

    // Construct the right subtree
    root->right = sortedlltobst(head, n - n / 2 - 1);

    return root;
}

// Merge two binary search trees (BSTs) into one balanced BST
node* mergetwobst(node* root1, node* root2) {
    // Convert both BSTs to sorted DLLs
    node* head1 = NULL;
    node* head2 = NULL;
    converttodll(root1, head1);
    converttodll(root2, head2);

    // Merge the two DLLs
    node* mergedHead = mergetwodll(head1, head2);

    // Count the number of nodes in the merged DLL
    int n = getnodes(mergedHead);

    // Convert the merged DLL back to a balanced BST
    return sortedlltobst(mergedHead, n);
}

// Perform level-order traversal of the binary tree
void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for the end of a level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            cout << endl;
            if (!q.empty()) {
                q.push(NULL); // Add marker for next level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    // Input the first BST
    cout << "Build the first BST: " << endl;
    node* root1 = buildtreefromlevelorder();

    // Input the second BST
    cout << "Build the second BST: " << endl;
    node* root2 = buildtreefromlevelorder();

    // Merge the two BSTs into one balanced BST
    node* mergedRoot = mergetwobst(root1, root2);

    // Perform level-order traversal of the merged BST
    cout << "Level-order traversal of the merged BST:" << endl;
    levelOrderTraversal(mergedRoot);

    return 0;
}
