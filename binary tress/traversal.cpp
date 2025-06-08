#include <iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* buildTree(node* root) {
    cout << "Enter data for node (-1 to indicate no node): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new node(data);
    cout << "Enter left child of " << data << ":\n";
    root->left = buildTree(root->left);
    cout << "Enter right child of " << data << ":\n";
    root->right = buildTree(root->right);

    return root;
}
node* buildTreeFromLevelOrder() {
    int data;
    cout << "Enter root node value: ";
    cin >> data;

    if (data == -1) return nullptr; // if root is -1, tree is empty

    // Create the root of the tree
    node* root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        // Left child
        cout << "Enter left child of " << current->data << ": ";
        cin >> data;
        if (data != -1) {
            current->left = new node(data);
            q.push(current->left);
        }

        // Right child
        cout << "Enter right child of " << current->data << ": ";
        cin >> data;
        if (data != -1) {
            current->right = new node(data);
            q.push(current->right);
        }
    }

    return root;
}

void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for level end

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl; // New line at the end of each level
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

// Inorder Traversal: Left, Root, Right
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal: Root, Left, Right
void preorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal: Left, Right, Root
void postorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = NULL;
    root = buildTree(root);

    cout<<"Level order Traversal: \n";
    levelOrderTraversal(root);

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);

    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);

    return 0;
}
 