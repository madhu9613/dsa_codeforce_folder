#include <iostream>
#include <queue>
#include <cmath>
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

node *buildtreefromlevelorder() {
    int data;
    cout << "Enter root data: ";
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    node *root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        // Left child input
     //   cout << "Enter left node of " << temp->data << ": ";
        cin >> data;
        if (data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }

        // Right child input
     //   cout << "Enter right node of " << temp->data << ": ";
        cin >> data;
        if (data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}
//level order traversal

bool isbalancedtree(node* root) {
    if (root == NULL) {
        return true;
    }

    bool found = true;
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            node* temp = q.front();
            q.pop();

            // Check balance for the current node
            if (abs(height(temp->left) - height(temp->right)) > 1) {
                found = false;
                break;
            }

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }

        if (!found) {
            break;
        }
    }
    return found;
}

bool inorderBalancedCheck(node* root) {
    if (root == NULL) {
        return true;
    }

    // Traverse left subtree
    if (!inorderBalancedCheck(root->left)) {
        return false;
    }

    // Check balance condition for current node
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    // Traverse right subtree
    return inorderBalancedCheck(root->right);
}
//optimising solution
pair<bool,int> isbalancedfast(node* root)
{
    if(root==NULL)
    {
        return {true,0};
    }
    pair<bool,int> left=isbalancedfast(root->left);
    pair<bool,int> right=isbalancedfast(root->right);
    bool diff=abs(left.second-right.second)<=1;

    int lans=left.first;
    int rans=right.first;
    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    if(lans&&rans&&diff)
    {
        ans.first=true;
    }
    else{
        ans.first=false;

    }
    return ans;
}

bool isidentical(node* r1, node* r2)
{
    if(r1==NULL && r2==NULL)
    {
        return true;
    }
    else if(r1==NULL && r2!=NULL)
    {
      return false;
    }
    else if(r1!=NULL && r2==NULL)
    {
        return false;
    }
    bool left=isidentical(r1->left, r2->left);
    bool right =isidentical(r1->right,r2->right);
    bool val=(r1->data==r2->data);
    if(left&& right&& val)
    {
        return true;
    }
    else{
        return false;
    }
}
int main() {
    node* root = buildtreefromlevelorder();


cout<<"by optimising\n";
pair<bool,int> result=isbalancedfast(root);
if(result.first)
{
    cout<<"BALANCED\n";
}
else{
    cout<<"UNBALANCED\n";
}

node* root2=buildtreefromlevelorder();
cout<<"by optimising\n";
pair<bool,int> result2=isbalancedfast(root2);
if(result2.first)
{
    cout<<"BALANCED\n";
}
else{
    cout<<"UNBALANCED\n";
}

if(isidentical(root,root2))
{
    cout<<"identical tree:\n";

}
else{
    cout<<"non identical tree\n";
}

    return 0;
}
