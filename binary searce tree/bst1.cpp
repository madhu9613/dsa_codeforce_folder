#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;

// Class for BST Node
class node
{
public:
    int data;    // Node value
    node *left;  // Pointer to left child
    node *right; // Pointer to right child

    // Constructor to initialize a new node
    node(int d)
    {
        this->data = d;
        this->left = this->right = NULL;
    }
};

// Function to insert a new node into the BST
node *inserttobst(node *root, int data)
{
    if (root == NULL)
    {
        // Create a new node if root is NULL
        root = new node(data);
        return root;
    }

    // Insert into the right subtree if data is greater
    if (data > root->data)
    {
        root->right = inserttobst(root->right, data);
    }
    // Insert into the left subtree otherwise
    else
    {
        root->left = inserttobst(root->left, data);
    }
    return root;
}

// Function to take input from the user to build the BST
void takeinput(node *&root)
{
    int data;
    cout << "Enter values to insert into BST (-1 to stop): " << endl;
    while (true)
    {
        cin >> data;
        if (data == -1)
            break; // Stop taking input when -1 is entered
        root = inserttobst(root, data);
    }
}

// Function for level order traversal (BFS)
void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // Add marker for next level
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// Function to search for a value in BST iteratively
bool searcebst(node *root, int x)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true; // Value found
        if (x > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false; // Value not found
}

// Function for inorder traversal (left-root-right)
void inorderTraversal(node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to find the minimum value in BST
node *min(node *root)
{
    if (root == NULL)
        return NULL; // Handle empty tree
    node *temp = root;
    while (temp->left)
        temp = temp->left;
    return temp;
}

// Function to find the maximum value in BST
node *max(node *root)
{
    if (root == NULL)
        return NULL; // Handle empty tree
    node *temp = root;
    while (temp->right)
        temp = temp->right;
    return temp;
}

// Function to find predecessor and successor of a given key
void presuc(node *root, node *&pre, node *&suc, int key)
{
    if (root == NULL)
        return;

    if (root->data == key)
    {
        // Find maximum in left subtree for predecessor
        if (root->left)
        {
            node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        // Find minimum in right subtree for successor
        if (root->right)
        {
            node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
    }
    else if (key < root->data)
    {
        suc = root; // Update successor
        presuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root; // Update predecessor
        presuc(root->right, pre, suc, key);
    }
}

// Function to delete a node in BST
node *deletenode(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        // Node to be deleted found
        // Case 1: Node with no children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: Node with one child
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node with two children
        else
        {
            node *temp = min(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

// Helper function for k-th smallest element
void inorderkth(node *root, int k, int &result, int &count)
{
    if (root == NULL)
        return;

    inorderkth(root->left, k, result, count);
    count++;
    if (count == k)
    {
        result = root->data;
        return;
    }
    inorderkth(root->right, k, result, count);
}

// Find k-th smallest element in BST
int kthmin(node *root, int k)
{nction for k-th largest element
void inorderreverse(node *root, int k, int &result, int &count)
{
    if (root == NULL)
        return;

    inorderreverse(root->right, k, result, count);
    count++;
    if (count == k)
    {
        result = root->data;
        return;
    }
    inorderreverse(root->left, k, result, count);
}

// Find k-th largest element in BST
int kthmax(node *root, int k)
{
    int result = -1, count = 0;
    inorderreverse(root, k, result, count);
    return result;
}
// lwest common ancestor
node *lca(node *root, int p, int q)
{
    if (root == NULL)
    {

        return root;
    }
    if (root->data > p && root->data > q)
    {

        // move to left part of tree::
        return lca(root->left, p, q);
    }
    if (root->data < p && root->data < q)
    {
        return lca(root->right, p, q);
    }

    return root;
}

void inorder(node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
void inorderrev(node *root, vector<int> &in)
{
    if (root == NULL)
        return;
    inorder(root->right, in);

    in.push_back(root->data);
    inorder(root->left, in);
}
pair<int, int> twosum(node *root, int key)
{
    vector<int> in;
    inorder(root, in);
    int left = 0;
    int right = in.size() - 1;

    while (left <= right)
    {
        if (in[left] + in[right] == key)
        {

            return make_pair(in[left], in[right]);
            break;
        }
        else if (in[left] + in[right] >= key)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return {-1, -1};
}
// flatten a bst to sorted linkedlist

node *flatten(node *root)
{
    vector<int> in;
    inorder(root, in);

    node *head = new node(in[0]);
    node *curr = head;
    for (int i = 1; i < in.size(); i++)
    {
        node *temp = new node(in[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }
    // last node
    curr->left = NULL;
    curr->right = NULL;

    return head;
}
node *decflatten(node *root)
{
    vector<int> in;
    inorderrev(root, in);

    node *head = new node(in[0]);
    node *curr = head;
    for (int i = 1; i < in.size(); i++)
    {
        node *temp = new node(in[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }
    // last node
    curr->left = NULL;
    curr->right = NULL;

    return head;
}
node* converttobst(int s, int e,vector<int> &in)
{
    if(s>e)
    {return NULL;}
    int mid=s+(e-s)/2;
    node* root=new node(in[mid]);
    root->left=converttobst(s,mid-1,in);
     root->right=converttobst(mid+1,e,in);
 return root;
}
node* balacncedbst(node* root)

{

vector<int> in;
inorder(root,in);
 return converttobst(0,in.size()-1,in);


}
//to check is bt is balanced and find height and diameter
struct TreeInfo {
    bool isBalanced;
    int height;
    int diameter;
};
TreeInfo checkBalancedHeightDiameter(node* root) {
    if (root == nullptr) {
        // A null tree is balanced, has height 0, and diameter 0
        return {true, 0, 0};
    }

    // Recursively check the left and right subtrees
    TreeInfo left = checkBalancedHeightDiameter(root->left);
    TreeInfo right = checkBalancedHeightDiameter(root->right);

    // Check if current tree is balanced
    bool isBalanced = left.isBalanced && right.isBalanced && abs(left.height - right.height) <= 1;

    // Height of the current tree is max height of left and right subtrees + 1 for current node
    // Here, leaf node height is considered as 1
    int currentHeight = 1 + max(left.height, right.height);

    // Diameter of the current tree is max of the diameter of left subtree,
    // right subtree, or the path through the root (leftHeight + rightHeight)
    int currentDiameter = max({left.diameter, right.diameter, left.height + right.height});

    return {isBalanced, currentHeight, currentDiameter};
}


// Main function
int main()
{
    node *root = NULL;
    takeinput(root);

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    cout << "Enter element to search: ";
    int x;
    cin >> x;
    if (searcebst(root, x))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    cout << "Inorder Traversal:" << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Minimum: " << min(root)->data << endl;
    cout << "Maximum: " << max(root)->data << endl;

    cout << "Enter key to find predecessor and successor: ";
    int key;
    cin >> key;
    node *pre = NULL, *suc = NULL;
    presuc(root, pre, suc, key);
    cout << "Predecessor: " << (pre ? to_string(pre->data) : "None") << endl;
    cout << "Successor: " << (suc ? to_string(suc->data) : "None") << endl;

    cout << "Enter key to delete: ";
    cin >> key;
    root = deletenode(root, key);

    cout << "Inorder after deletion:" << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Enter value of k: ";
    int k;
    cin >> k;
    cout << "K-th Min: " << kthmin(root, k) << endl;
    cout << "K-th Max: " << kthmax(root, k) << endl;

    // lowest common ancestor
    int p, q;
    cout << "enter p and q " << endl;
    cin >> p >> q;
    node *l = lca(root, p, q);
    cout << "lca is " << l->data << endl;

    // two sum target

    cout << "enter key for sum" << endl;
    cin >> key;

    pair<int, int> result = twosum(root, key);
    if (result.first != -1)
    {
        cout << "pairs are " << result.first << " " << result.second << endl;
    }
    else
    {
        cout << "NOT EXIST" << endl;
    }

    node *head = flatten(root);
    cout << "printing flatten linked list making from the bst" << endl;
    node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data;
        if (temp->right != NULL)
        {
            cout << " ->";
        }
        temp = temp->right;
    }


    node* head2 = decflatten(root);

    cout << "Printing decreasing flatten linked list made from the BST:" << endl;
    node *temp2 = head2;
    while (temp2 != NULL)
    {
        cout << temp2->data;
        if (temp2->right != NULL)
        {
            cout << " -> ";
        }
        temp2 = temp2->right;
    }
    cout << endl;





//converting the tree to balanced binary searce tree with min height
root=balacncedbst(root);
cout<<"printing level order again:"<<endl;
levelOrderTraversal(root);
//to check isit balanced and find height and diameter

TreeInfo answer=checkBalancedHeightDiameter(root);
cout<<"is balanced :"<<(answer.isBalanced?"yes":"no");
cout<<"HEIGHT is :"<<answer.height<<endl;
cout<<"diameter is:"<<answer.diameter<<endl;
    return 0;
}