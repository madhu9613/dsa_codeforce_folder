#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = this->right = NULL;
    }
};

// Function to build a binary tree from level order input
node* buildTreeFromLevelOrder() {
    int data;
    cout << "Enter root node value (-1 for null): ";
    cin >> data;

    if (data == -1) return nullptr; // If root is -1, tree is empty

    node* root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
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

// Inorder traversal function to fill the vector
void inorder(node* root, vector<int>& in) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, in);
    cout << root->data << " "; // Print the node value during traversal
    in.push_back(root->data);
    inorder(root->right, in);
}

// Function to check if the binary tree is a BST
/*here i store this inorder in a vector and just check that is the vector is sorted or not if yes then it
bst otherwise its not
*/
bool isvaidbst(node* root) {
    vector<int> in;
    inorder(root, in);
    bool ans = true;
    for (int i = 0; i < in.size() - 1; i++) {
        if (in[i] > in[i + 1]) {
            ans = false;
            break;
        }
    }
    return ans;
}
//optimal solution as here  i am using range
bool isbst(node* root,int min, int max)
{

    if(root==NULL)

    {
        return true;
    }
    if(root->data>=min && root->data<=max)
    {
               bool left=isbst(root->left,min,root->data);
               bool right=isbst(root->right,root->data,max);

               return left && right;

    }
    else{
        return false;
    }
}
int main() {
    node* root = buildTreeFromLevelOrder();
int min=INT_MIN;
int max=INT_MAX;
    if (isbst(root,min,max)) { 
        cout << "\nBinary tree is a BST" << endl;
    } else {
        cout << "\nBinary tree is not a BST" << endl;
    }

    return 0;
}
