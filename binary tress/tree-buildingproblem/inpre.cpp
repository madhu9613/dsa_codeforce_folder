#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build the tree from inorder and preorder
Node* buildTree(vector<int>& inorder, vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
    if (inStart > inEnd) return nullptr;

    // Create a new node with the current preorder index
    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    // Find the index of this root in the inorder traversal
    int inIndex = inorderMap[rootVal];

    // Recursively construct left and right subtrees
    root->left = buildTree(inorder, preorder, preIndex, inStart, inIndex - 1, inorderMap);
    root->right = buildTree(inorder, preorder, preIndex, inIndex + 1, inEnd, inorderMap);

    return root;
}

// Function to print the inorder traversal of the tree (for validation)
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), preorder(n);
    
    // Read inorder and preorder traversals
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> preorder[i];

    // Create a hash map for quick lookup of inorder indices
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }

    int preIndex = 0;  // Preorder traversal index
    Node* root = buildTree(inorder, preorder, preIndex, 0, n - 1, inorderMap);

    // Print inorder traversal of the constructed tree to verify correctness
    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
