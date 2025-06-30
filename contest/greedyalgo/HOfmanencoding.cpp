/*

Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

Example 1:

S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output:
0 100 101 1100 1101 111
Explanation:
Steps to print codes from Huffman Tree
HuffmanCodes will be:


f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111

Hence printing them in the PreOrder of Binary
Tree.
*/

#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int data; // it will store the frequency count
    node *left;
    node *right;
    node(int data)

    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{

    void traverse(node *root, string temp, vector<string> ans)
    {
        if (root->left == NULL && root->right == NULL)

        {
            ans.push_back(temp); 
            return;
        }
        traverse(root,temp+'0',ans);
        traverse(root,temp+'0',ans);

    }



public:
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<node *, vector<node *>, compare> pq;
        // crete A min heap of the data
        for (int i = 0; i < N; i++)
        {
            node *temp = new node(f[i]);
            pq.push(temp);
        }

        //    ---- now i will create a tree for it
        while (pq.size() > 1)
        {
            node *left = pq.top();
            pq.pop();
            node *right = pq.top();
            pq.pop();

            node *newnode = new node(left->data + right->data);
            newnode->left = left;
            newnode->right = right;

            pq.push(newnode);
        }
        node *root = pq.top();
        string temp = "";
        vector<string> ans;
        traverse(root, temp, ans);

        return ans;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
