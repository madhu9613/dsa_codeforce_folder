#include <iostream>
#include <queue>
using namespace std;

// Generic class for a Binary Tree Node
template <typename T>
class TreeNode {
public:
    T data;              // Data of the node
    TreeNode<T> *left;   // Pointer to left child
    TreeNode<T> *right;  // Pointer to right child

    // Constructor to initialize a new node
    TreeNode(T data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Generic Binary Tree class
template <typename T>
class BinaryTree {
private:
    TreeNode<T> *root; // Root of the binary tree

    // Helper function for insertion
    TreeNode<T> *insertToBST(TreeNode<T> *node, T data) {
        if (node == nullptr) {
            return new TreeNode<T>(data);
        }
        if (data > node->data) {
            node->right = insertToBST(node->right, data);
        } else {
            node->left = insertToBST(node->left, data);
        }
        return node;
    }

    // Helper function for inorder traversal
    void inorder(TreeNode<T> *node) const {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for level order traversal
    void levelOrder(TreeNode<T> *node) const {
        if (node == nullptr) return;

        queue<TreeNode<T> *> q;
        q.push(node);
        q.push(nullptr);

        while (!q.empty()) {
            TreeNode<T> *temp = q.front();
            q.pop();

            if (temp == nullptr) {
                cout << endl;
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                cout << temp->data << " ";
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
    }

    // Helper function for searching a value
    bool search(TreeNode<T> *node, T key) const {
        while (node != nullptr) {
            if (node->data == key) return true;
            node = (key > node->data) ? node->right : node->left;
        }
        return false;
    }

    // Helper function to find the minimum node
    TreeNode<T> *findMin(TreeNode<T> *node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    // Helper function to find the maximum node
    TreeNode<T> *findMax(TreeNode<T> *node) const {
        while (node && node->right) node = node->right;
        return node;
    }

    // Helper function for deletion
    TreeNode<T> *deleteNode(TreeNode<T> *node, T key) {
        if (node == nullptr) return nullptr;

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                TreeNode<T> *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode<T> *temp = node->left;
                delete node;
                return temp;
            }
            TreeNode<T> *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Helper function for k-th smallest element
    void findKthMin(TreeNode<T> *node, int &count, int k, T &result) const {
        if (node == nullptr) return;

        findKthMin(node->left, count, k, result);
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
        findKthMin(node->right, count, k, result);
    }

    // Helper function for k-th largest element
    void findKthMax(TreeNode<T> *node, int &count, int k, T &result) const {
        if (node == nullptr) return;

        findKthMax(node->right, count, k, result);
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
        findKthMax(node->left, count, k, result);
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Insert a value into the binary tree
    void insert(T data) {
        root = insertToBST(root, data);
    }

    // Perform inorder traversal
    void inorderTraversal() const {
        inorder(root);
        cout << endl;
    }

    // Perform level order traversal
    void levelOrderTraversal() const {
        levelOrder(root);
    }

    // Search for a value in the tree
    bool search(T key) const {
        return search(root, key);
    }

    // Find the minimum value
    T findMin() const {
        TreeNode<T> *minNode = findMin(root);
        return (minNode) ? minNode->data : T();
    }

    // Find the maximum value
    T findMax() const {
        TreeNode<T> *maxNode = findMax(root);
        return (maxNode) ? maxNode->data : T();
    }

    // Delete a node with the given key
    void deleteValue(T key) {
        root = deleteNode(root, key);
    }

    // Find k-th smallest element
    T kthSmallest(int k) const {
        T result = T();
        int count = 0;
        findKthMin(root, count, k, result);
        return result;
    }

    // Find k-th largest element
    T kthLargest(int k) const {
        T result = T();
        int count = 0;
        findKthMax(root, count, k, result);
        return result;
    }
};

// Main function
int main() {
    BinaryTree<int> bt;

    cout << "Enter values to insert into the binary tree (-1 to stop):" << endl;
    int value;
    while (true) {
        cin >> value;
        if (value == -1) break;
        bt.insert(value);
    }

    cout << "Inorder Traversal:" << endl;
    bt.inorderTraversal();

    cout << "Level Order Traversal:" << endl;
    bt.levelOrderTraversal();

    cout << "Enter a value to search: ";
    cin >> value;
    cout << (bt.search(value) ? "Found" : "Not Found") << endl;

    cout << "Minimum Value: " << bt.findMin() << endl;
    cout << "Maximum Value: " << bt.findMax() << endl;

    cout << "Enter a value to delete: ";
    cin >> value;
    bt.deleteValue(value);
    cout << "Inorder after deletion:" << endl;
    bt.inorderTraversal();

    cout << "Enter k for k-th smallest element: ";
    int k;
    cin >> k;
    cout << "K-th Smallest: " << bt.kthSmallest(k) << endl;

    cout << "Enter k for k-th largest element: ";
    cin >> k;
    cout << "K-th Largest: " << bt.kthLargest(k) << endl;

    return 0;
}
