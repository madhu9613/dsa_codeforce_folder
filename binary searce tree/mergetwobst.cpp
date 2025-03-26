#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTreeFromLevelOrder() {
    int data;
    cout << "Enter root node value (-1 for null): ";
    cin >> data;

    if (data == -1)
        return nullptr; // If root is -1, tree is empty

    node *root = new node(data);
    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        node *current = q.front();
        q.pop();

        // Left child
        cin >> data;
        if (data != -1) {
            current->left = new node(data);
            q.push(current->left);
        }

        // Right child
        cin >> data;
        if (data != -1) {
            current->right = new node(data);
            q.push(current->right);
        }
    }

    return root;
}

void inorder(node *root, vector<int> &in) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void mergeTwoSortedArrays(vector<int> &in1, vector<int> &in2, vector<int> &in) {
    int r1 = in1.size();
    int r2 = in2.size();
    int i = 0, j = 0;

    while (i < r1 && j < r2) {
        if (in1[i] < in2[j]) {
            in.push_back(in1[i++]);
        } else {
            in.push_back(in2[j++]);
        }
    }
    // Copy remaining elements
    while (i < r1) {
        in.push_back(in1[i++]);
    }
    while (j < r2) {
        in.push_back(in2[j++]);
    }
}

node *convertInorderToBST(int s, int e, vector<int> &in) {
    if (s > e) {
        return NULL;
    }
    int mid = s + (e - s) / 2;
    node *root = new node(in[mid]);
    root->left = convertInorderToBST(s, mid - 1, in);
    root->right = convertInorderToBST(mid + 1, e, in);
    return root;
}

node *mergeTwoBSTs(node *root1, node *root2) {
    vector<int> in1, in2, mergedInorder;

    // Perform inorder traversal on both BSTs
    inorder(root1, in1);
    inorder(root2, in2);

    // Merge the two sorted inorder traversals
    mergeTwoSortedArrays(in1, in2, mergedInorder);

    // Convert the merged sorted array to a balanced BST
    return convertInorderToBST(0, mergedInorder.size() - 1, mergedInorder);
}

void levelOrderTraversal(node *root) {
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            cout << endl;
            if (!q.empty()) {
                q.push(NULL); // Add marker for next level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main() {
    cout << "Building first tree..." << endl;
    node *root1 = buildTreeFromLevelOrder();

    cout << "Building second tree..." << endl;
    node *root2 = buildTreeFromLevelOrder();

    node *mergedRoot = mergeTwoBSTs(root1, root2);

    cout << "Level Order Traversal of Merged Tree:" << endl;
    levelOrderTraversal(mergedRoot);

    return 0;
}
