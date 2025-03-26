/*
the problem is to convert the given BST into a Min Heap with
 the condition that all the values in the left subtree of a node should be

  less than all the values in the right subtree of the node. This condition is applied to
  all the nodes, in the resultant converted Min Heap

APPROCH--->

1) important that the given bst already a cbt so donot actually need to change the structure
store this inoder sequence-.as for bst inorder is sorted way
here we have the condition that N <L AND N<R  AND  also l<r so finally it become that n<l<r so....
Nlr is preorder so we can fill the arrey in preorder wise in the the bst...
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node
{

public:
    int data;
    node *left;
    node *right;
    node(int data)

    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// build tree from level order traversal
node *buildtreefromlevelorder()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        // for left;
        cin >> data;
        if (data != -1)
        {
            root->left = new node(data);
            q.push(root->left);
        }
        // for right data;
        cin >> data;
        if (data != -1)
        {
            root->right = new node(data);
            q.push(root->right);
        }
    }
}
//store inorder traversal;
void inorder(node* root,vector<int> &in)
{
    if(root==NULL)
    {
        return;
    }
    // LNR 
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
void preorderFill(node* root, vector<int>& inorderArr, 
                                             int& index) {
    if (root == nullptr) {
        return;
    }

    root->data = inorderArr[index++];

    preorderFill(root->left, inorderArr, index);  
    preorderFill(root->right, inorderArr, index);
}
void creatminorder(node* root)
{

    vector<int> in;
    inorder(root,in);
    int index=0;
    preorderFill(root,in,index);
}
int main()
{

    return 0;
}