#include <iostream>
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
        this->left = this->right = NULL;
    }
};
node *buildtreefromlevelorder()
{
    int data;
    cout << "ENTER DATA:\n";
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
        // left
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        // right:
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}
void findLongestPathSum(node *root, int currentSum, int currentLength, int &maxSum, int &maxLength)
{
    if (root == nullptr)
    {
        return;
    }

//add this root 
    currentSum += root->data;
    currentLength++;

    // Check if it's a leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
        // Update max length and max sum if this path is the longest or if it's the same length but with a higher sum
        if (currentLength > maxLength || (currentLength == maxLength && currentSum > maxSum))
        {
            maxLength = currentLength;
            maxSum = currentSum;
        }
    }

    // Traverse the left and right children
    findLongestPathSum(root->left, currentSum, currentLength, maxSum, maxLength);
    findLongestPathSum(root->right, currentSum, currentLength, maxSum, maxLength);
}

int sumOfLongestPath(node *root)
{
    int maxSum = 0;
    int maxLength = 0;
    findLongestPathSum(root, 0, 0, maxSum, maxLength);
    return maxSum;
}





node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    
    node *leftans = lca(root->left, n1, n2);
    node *rightans = lca(root->right, n1, n2);
    if (leftans != NULL && rightans != NULL)
    {
        return root;
    }
    else if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    else if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }
    else
    {
        return NULL;
    }
}


int main()
{
    node* root=buildtreefromlevelorder();
    cout<<"sum of longest path is :\n";
    int sum=sumOfLongestPath(root);
    cout<<sum<<endl;
    int n1,n2;
    cin>>n1>>n2;
    node* LCA=lca(root,n1,n2);
    cout<<"lowest common anncestor is:\n";
    cout<<LCA->data<<endl;
    return 0;
}
