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

        this->left = nullptr;
        this->right = nullptr;
    }
};
node *buildtreefromlevelorder()
{
    int data;
    cout << "enter root data\n";
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
        // left node for temp;
        cout << "enter left node of :" << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        // right
        cout << "enter right node of :" << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}
int heightofBTrecursion(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = heightofBTrecursion(root->left);
    int rightheight = heightofBTrecursion(root->right);
    int h = max(leftheight, rightheight) + 1;
    return h;
}

// - - using level order traversal 
int heightofbt(node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    queue<node*> q;
    q.push(root);
    int height=0;
    while(!q.empty())
    {
        int levelsize=q.size();
        height++;
        for(int i=0;i<levelsize;i++)
        {
            node* temp=q.front();
            q.pop();
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
    return height;

}

int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=heightofbt(root->left)+1+heightofbt(root->right); //height of left + the root + height of right 

int d=max(op1,max(op2,op3)); //jo bhi maxima wohi answer

return d;

//time complexity :O(n^2);
/*we are clling height function so its complexity is become big but if we use a another data structure
 pair means in single iteration we will calculate height and diameter both simultaneously

*/
}
pair<int,int> diameterheight(node* root)

{
    if(root==NULL)
    {
        return {0,0};
    }
    pair<int,int> left=diameterheight(root->left);

    pair<int,int> right=diameterheight(root->right);
    int d1=left.first;
    int d2=right.first;

    int d3=left.second +right.second+1;

    pair<int,int> ans;
    ans.first=max(d1,max(d2,d3)); //for diameter
    ans.second=max(left.second,right.second)+1; //for height 

     return ans;
    
}
int main()
{

    node *root = buildtreefromlevelorder();
    /*
    example :
         1
      2     3
    4   5      6
      7
      level:
      1
      2 3
      4 5 -1 6
    - 1 -1 7 -1 -1 -1
    // input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    */

int h1=heightofBTrecursion(root);
cout<<"height of the tree using recursion::\n";
cout<<h1;
cout<<endl;
int h2=heightofbt(root);
cout<<"height of the tree without using recursion::\n";
cout<<h2<<endl;
int Diameter=diameter(root);
cout<<"diameter of the tree is "<<Diameter<<endl;
pair<int,int> ans=diameterheight(root);
cout<<"diameter and height is: "<<ans.first<<" , "<<ans.second<<endl;
    return 0;
}