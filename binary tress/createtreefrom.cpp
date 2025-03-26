#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to construct the binary tree
Node* buildTreeHelper(vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Get the root from the current position of preorder
    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    // Find the index of the root in the inorder array
    int inIndex = inMap[rootVal];

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = buildTreeHelper(preorder, preIndex, inIndex + 1, inEnd, inMap);

    return root;
}

// Function to construct the binary tree
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;

    // Store the indices of inorder elements in a map for quick lookup
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    int preIndex = 0; // Pointer to the current root in preorder traversal
    return buildTreeHelper(preorder, preIndex, 0, inorder.size() - 1, inMap);
}

// Helper function to print the tree in inorder traversal
void inorderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

// Helper function to print the tree in preorder traversal
void preorderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    // Example Input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build the tree
    Node* root = buildTree(preorder, inorder);

    // Print the traversals to verify
    cout << "Inorder Traversal of Constructed Tree: ";
    inorderPrint(root);
    cout << endl;

    cout << "Preorder Traversal of Constructed Tree: ";
    preorderPrint(root);
    cout << endl;

    return 0;
}
