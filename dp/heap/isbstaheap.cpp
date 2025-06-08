/*
 is binary tree is a heap or not:::
 return true or false...
 check is the binary tree is cbt or not and check is it in  max order
    IMP NOTES::
    in zero based indexing if i am at ith index then--->>>
    leftchild =2*i+1
    rightchild=2*i+2;
for CBT:
if left/right> total number of nodes then its not a cbt;;
*/
#include <bits/stdc++.h>
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
node *buildtrefromlevelorder()
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
    if (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        // left part
        cin >> data;
        if (data != -1)
        {
            root->left = new node(data);
            q.push(root->left);
        }

        // right part
        cin >> data;
        if (data != -1)
        {
            root->right = new node(data);
            q.push(root->right);
        }
    }
    return root;
}

int total(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + total(root->right) + total(root->left);
}

bool iscbt(node *root, int index, int totalcount)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= totalcount)
    {
        return false;
    }

    bool left = iscbt(root->left, 2 * index + 1, totalcount);
    bool right = iscbt(root->right, 2 * index + 2, totalcount);
    return left && right;
}

// check is follow max order as heap
/*
        what are the possible cases:::

-> if its a leaf node then obiously it will be in maxorder
-> if it has only can have left child (means we will come here only after checking that its a cbt)
->if both the child present check condition for maxheap


*/
bool ismaxorder(node *root)

{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->right == NULL)
    {
        return root->data > root->left->data; // t or false;
    }

    bool left = ismaxorder(root->left);
    bool right = ismaxorder(root->right);

    /*
    its left and right child should be in maxorder and  itself should be in maxorder also
    */
    return left && right && root->data > root->left->data && root->data > root->right->data;
}
bool isheap(node *root)
{

    int n = total(root);
    int index = 0;
    return iscbt(root, index, n) && ismaxorder(root);
}
int main()
{
    node* root=buildtrefromlevelorder();
    bool result=isheap(root);
    if(result)
    {
        cout<<" Given Binary Tree is HEap "<<endl;
    }
    else{
        cout<<"ITS a not tree"<<endl;
    }
    return 0;
}