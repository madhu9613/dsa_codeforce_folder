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

void inorder(node* root, node* &head,node* &prev)
{
if(root==NULL)
{
    return ;
}
//go to left
inorder(root->left,head,prev);
if(prev==NULL)
{
    head=root;
}
else{
    
prev->right=root;

}
prev=root;
prev->left=NULL;

//go to right;
inorder(root->right,head,prev);

}
node* tolinkedlist(node* root)
{
  node* head=NULL;
  node* prev=NULL;
  inorder(root,head,prev);

  if(prev !=NULL)
  {
    prev->right=NULL;
  }
  return head;


}




int main()

{
node* root=buildtreefromlevelorder();

    return 0;
}