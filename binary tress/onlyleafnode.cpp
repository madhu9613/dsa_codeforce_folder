#include <iostream>
#include <queue>
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
    cout << "Enter root node value: \n ";
    cin >> data;
    
    if (data == -1) {
        return NULL;
    }
   
    node* root = new node(data);
    queue<node*> q;
    q.push(root);
   
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        // Left child
        cout << "Enter data for left child of \n" << temp->data << ": ";
        cin >> data;
        if (data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }

        // Right child
        cout << "Enter data for right child of \n" << temp->data << ": ";
        cin >> data;
        if (data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}

int leafCount(node* root) {
    if (root == NULL) {
        return 0;
    }

    int leafCount = 0;
    queue<node*> q;
    q.push(root);

    cout << "Leaf nodes are: ";
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        // Check if it is a leaf node
        if (temp->left == NULL && temp->right == NULL) {
            cout << temp->data << " ";
            leafCount++;
        }

        // Add children to queue if they exist
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
    
    return leafCount;
}
int inorderleafcount(node* root,int &count)

{
    if(root==NULL)
    {
        return 0;
    }
    inorderleafcount(root->left,count);
    if(root->left==NULL && root ->right==NULL)
    {
        count++;
    }
    inorderleafcount(root->right,count);
    return count;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
    node* root = buildTreeFromLevelOrder();
    // int lc = leafCount(root);
    int count=0;
    int lc=inorderleafcount(root,count);
    cout << "Total leaf count is: " << lc << endl;
    }

    return 0;
}
