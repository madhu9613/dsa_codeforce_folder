#include<iostream>
#include<queue>
using namespace std;
class node{

public:
int data;
node* left;
node* right;
node(int data)
{
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};
node* buildtreefromlevelorder()

{
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    if(data==-1)
    {
        return nullptr;
    }
    node* root=new node(data);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        //for left:
        cin>>data;
        if(data!=-1)
        {
            temp->left=new node(data);
            q.push(temp->left);
        }
        //right

        cin>>data;
        if(data!=-1)
        {
            temp->right=new node(data);
            q.push(temp->right);
        }
    }
    return root;
}
class info{
    public:
    int maxi;
    int mini;
    int size;
    bool isbst;

};
info solve(node* root, int& maxsize)
{
    if(root==NULL)
    {
        return{INT_MIN,INT_MAX,0,true};
    }
info left=solve(root->left,maxsize);
info right=solve(root->right,maxsize);
//curre node'
info currentnode;
currentnode.size=left.size+right.size+1;
currentnode.maxi=max(root->data,right.maxi);
currentnode.mini=min(root->data,left.mini);
if(left.isbst && right.isbst && root->data <right.mini && root->data >left.maxi)

{
    currentnode.isbst=true;
}
else{
    currentnode.isbst=false;
}

}
int largestbst(node* root)
{
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}
int main()
{
    return 0;
    node* root=buildtreefromlevelorder();
}