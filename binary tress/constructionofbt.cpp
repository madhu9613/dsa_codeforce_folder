#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data) : data(data), left(NULL), right(NULL) {}
};

// Function to find the position of an element in the inorder array
int findpos(vector<int>& in, int element) {
    int n = in.size();
    for (int i = 0; i < n; i++) {
        if (in[i] == element) {  // Compare with element in inorder
            return i;
        }
    }
    return -1;  // If not found (this case should not happen if input is valid)
}

// Function to create the binary tree using inorder and preorder traversals

node* creat(vector<int>& in, vector<int>& pre, int& preorderindex, int inorderstart, int inorderend, int n) {
    if (preorderindex >= n || inorderstart > inorderend) {
        return NULL;
    }

    int element = pre[preorderindex++];
    node* root = new node(element);
    
    int pos = findpos(in, element);

    // Recursively build the left subtree
    root->left = creat(in, pre, preorderindex, inorderstart, pos - 1, n);
    
    // Recursively build the right subtree
    root->right = creat(in, pre, preorderindex, pos + 1, inorderend, n);

    return root;
}

// Function to print the postorder traversal of the tree
void postorder(node* root) {
    if (root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}


int main() {
    int n;
    cin >> n;
    
    vector<int> in, pre; // Create vectors for inorder and preorder
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        in.push_back(data);
    }
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        pre.push_back(data);
    }

    int preorderindex = 0;
    int inorderstart = 0;
    int inorderend = n - 1;

    node* root = creat(in, pre, preorderindex, inorderstart, inorderend, n);

    // Printing the postorder traversal
    postorder(root);

    return 0;

}
