#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> parent;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct Pair
{
    int dia;
    int ht;
    /* data */
};

node *buildtreefromlevelorder()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    node *root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        // left childl;
        cin >> data;
        if (data != -1)
        {
            current->left = new node(data);
            q.push(current->left);
        }
        // right child
        cin >> data;
        if (data != -1)
        {
            current->right = new node(data);
            q.push(current->right);
        }
    }
    return root;
}
// lets revise traversal ;
void level_order_traversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder_traversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    //left node right
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
void preorder_traversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void post_ordertraversal(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    post_ordertraversal(root->left);
    post_ordertraversal(root->right);
    cout<<root->data<<" ";
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}
Pair htanddia(node* root)
{
    if(root==NULL)
    {
        return {0,0};
    }
    Pair left=htanddia(root->left);
    Pair right=htanddia(root->right);
    int op1=left.dia;
    int op2=right.dia;
    int op3=left.ht +right.ht+1;
    Pair ans;
   ans.dia=max(op1,max(op2,op3));
   ans.ht=max(left.ht,right.ht)+1;
   return ans;
}
void findlongestpathsun(node* root,int cursum, int curlength,int &maxsum,int &maxlength)
{
    if(root==nullptr)
    {
        return;
    }
    //add the current node to sum;
    cursum+=root->data;
    curlength++;
    if(root->left==nullptr && root->right==nullptr)
    {
        if(curlength>maxlength ||(curlength==maxlength)&&(cursum>maxsum))
        {
            maxlength=curlength;
            maxsum=cursum;
        }
    }
 findlongestpathsun(root->left,cursum,curlength,maxsum,maxlength);
 findlongestpathsun(root->right,cursum,curlength,maxsum,maxlength);

}
int sumoflongestpath(node* root)
{
    int maxsum=INT_MIN;
    int maxlength=0;
    findlongestpathsun(root,0,0,maxsum,maxlength);
    return maxsum;
}

//k sum path number of path with sum is equal to k
void ksum(node* root,vector<int>& path,int k,vector<vector<int>>&result)
{
    //its kinda preorder

    if(!root)
    {
        return;
    }
    path.push_back(root->data);
    int sum=0;
    vector<int> temp;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum+=path[i];
        temp.insert(temp.begin(),path[i]);
        if(sum==k)
        {
            result.push_back(temp);
        }
    }
    //left subtree;
    ksum(root->left,path,k,result);
    ksum(root->right,path,k,result);

    path.pop_back();
}

//its code to find kth ancestor in a bt
int k_Ancestor(node* root, int val, int& k) {
    if (root == nullptr) {
        return -1; // Not found
    }

    if (root->data == val) {
        return 1; // Found the target node
    }

    int left = k_Ancestor(root->left, val, k);
    int right = k_Ancestor(root->right, val, k);

    if (left == 1 || right == 1) {
        k--; // Move one level up
        if (k == 0) {
            cout << "K-th Ancestor: " << root->data << endl;
            return 0; // Stop further recursion
        }
        return 1; // Continue the search upwards
    }

    return -1; // Not found in this path
}

//lets find kth ancestor using iterative approach in cpp using bfs we will store parents of a node then proceeds 
void store_parent(node* root)
{
    if(!root)
    {
        return ;
    }
    queue<node*>q;
    q.push(root);
    //parent of root is always -1
    parent[root->data]=-1;
    while (!q.empty())
    {
       node* temp=q.front();
       q.pop();
       if(temp->left)
       {
        parent[temp->left->data]=temp->data;
        q.push(temp->left);
       }
       if(temp->right)
       {
        parent[temp->right->data]=temp->data;
        q.push(temp->right);
       }

    }

}
int kth_bfs(node* root,int k,int val)
{
    int ans=val;
    while (k>0 && parent[ans]!=-1)
    {
        ans=parent[ans];
        k--;
    }
    return k==0?ans:-1;
}
int main()
{
    node* root=buildtreefromlevelorder();
    cout<<"Level order Traversal: \n";
    level_order_traversal(root);

    cout << "\nInorder Traversal: ";
    inorder_traversal(root); 

    cout << "\nPreorder Traversal: ";
    preorder_traversal(root);

    cout << "\nPostorder Traversal: ";
    post_ordertraversal(root);
   
    cout<<endl;
    Pair ht_and_dia=htanddia(root);
    cout<<ht_and_dia.dia<<" "<<ht_and_dia.ht<<endl;

   vector<int>path;
   vector<vector<int> >result;
   ksum(root,path,5,result);
   cout << "Paths with sum " << 5 <<":\n";
   for (auto& p : result) {
       cout << "[ ";
       for (int num : p) cout << num << " ";
       cout << "]\n";
   }
   int val=5,k=2;
   k_Ancestor(root,val,k);
int kans=kth_bfs(root,k,val);
cout<<kans<<endl;
 
}