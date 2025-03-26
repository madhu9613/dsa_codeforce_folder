///very important file....

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

node* buildtreefromlevelorder() {
    int data;
    cout << "Enter root data: ";
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    node *root = new node(data);
    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        // Left child input
        cin >> data;
        if (data != -1) { 
            temp->left = new node(data);
            q.push(temp->left);
        }

        // Right child input
        cin >> data;
        if (data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}

void zigziag(node *root, vector<int> &result) {
    if (root == NULL) {
        return;
    }

    queue<node *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);

        for (int i = 0; i < n; i++) {
            node *temp = q.front();
            q.pop();

            // Decide position based on the current traversal direction
            int index = leftToRight ? i : (n - 1 - i);
            level[index] = temp->data;

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }

        // Append the current level to the result
        result.insert(result.end(), level.begin(), level.end());
        // Toggle direction
        leftToRight = !leftToRight;
    }
}
//left part printing
void printleft(node *root, vector<int> &result) {
    if (root == NULL) {
        return;
    }

    node *temp = root->left;

    // Traverse the left boundary
    while (temp) {
        // Add to result only if it's not a leaf node
        if (temp->left != NULL || temp->right != NULL) {
            result.push_back(temp->data);
        }

        // Move to the left if possible, otherwise to the right
        if (temp->left) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
}
//leafnode printing

void printleafnode(node *root, vector<int> &result) {
    if (root == NULL) {
        return;
    }
    printleafnode(root->left, result);
    if (root->left == NULL && root->right == NULL) {
        result.push_back(root->data);
    }
    printleafnode(root->right, result);
}

void printrightnodefrombottom(node *root, vector<int> &ans) {
    vector<int> result;
    if (root == NULL) {
        return;
    }

    node *temp = root->right;

    // Traverse the right boundary
    while (temp) {
        // Add to result only if it's not a leaf node
        if (temp->left != NULL || temp->right != NULL) {
            result.push_back(temp->data);
        }

        // Move to the right if possible, otherwise to the left
        if (temp->right) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    reverse(result.begin(), result.end());
    ans.insert(ans.end(), result.begin(), result.end());
}

vector<int> boundarytraversal(node *root) {
    vector<int> result;
    if (root == NULL) return result; // Handle empty tree case

    result.push_back(root->data);
    printleft(root, result);
    printleafnode(root, result);
    printrightnodefrombottom(root, result);
    return result;
}

//very important vertical order traversal

vector<int> verticalordertraversal(node *root) {
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node*, pair<int, int>>> q;

    vector<int> result;
    if (root == NULL) {
        return result;
    }

    q.push(make_pair(root, make_pair(0, 0)));
    
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        node *temp = front.first;
        int hd = front.second.first;
        int lvl = front.second.second;

        nodes[hd][lvl].push_back(temp->data);
        
        if (temp->left) {
            q.push(make_pair(temp->left, make_pair(hd - 1, lvl + 1)));
        }
        if (temp->right) {
            q.push(make_pair(temp->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    for (auto i : nodes) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                result.push_back(k);
            }
        }
    }
    return result;
}


 
vector<int> topview(node* root) {
    map<int,int> m;
    queue<pair<node*,int>> q;
    vector<int> ans;

    if (root == NULL) return ans; // Handle empty tree case

    q.push(make_pair(root,0));
    
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        node* temp = front.first;
        int hd = front.second;

        if(m.find(hd) == m.end()) { // Only add the first occurrence
            m[hd] = temp->data;
        }
        if(temp->left) {
            q.push(make_pair(temp->left,hd-1));
        }
        if(temp->right) {
            q.push(make_pair(temp->right,hd+1));
        }
    }

    for(auto i : m) {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomview(node* root) {
    map<int,int> m;
    queue<pair<node*,int>> q;
    vector<int> ans;

    if (root == NULL) return ans; // Handle empty tree case

    q.push(make_pair(root,0));
    
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        node* temp = front.first;
        int hd = front.second;

        m[hd] = temp->data; // Update to the last occurrence
        if(temp->left) {
            q.push(make_pair(temp->left,hd-1));
        }
        if(temp->right) {
            q.push(make_pair(temp->right,hd+1));
        }
    }

    for(auto i : m) {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> leftView(node* root) {
    vector<int> result;

    if (root == nullptr) return result;

    queue<node*> q;
    q.push(root);
   
    while (!q.empty()) {
        int n = q.size();
        
        // Traverse each level
        for (int i = 0; i < n; i++) {
            node* temp = q.front();
            q.pop();

            // If it's the first node of this level, print it
            if (i == 0) {
                result.push_back(temp->data);
            }

            // Push left and right children to the queue
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return result;
}

int main() {
    node *root = buildtreefromlevelorder();
    vector<int> ans;

    // Zigzag Traversal
    zigziag(root, ans);
    cout << "Printing in zigzag pattern: " << endl;
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    // Boundary Traversal
    cout << "Printing in boundary traversal: " << endl;
    vector<int> btraversal = boundarytraversal(root);
    for (int val : btraversal) {
        cout << val << " ";
    }
    cout << endl;

    // Vertical Order Traversal
    cout << "Printing in vertical order traversal: " << endl;
    vector<int> vtraversal = verticalordertraversal(root);
    for (int val : vtraversal) {
        cout << val << " ";
    }
    cout << endl;

    // Top View
    cout << "Printing the top view of the tree: " << endl;
    vector<int> top = topview(root);
    for (int val : top) {
        cout << val << " ";
    }
    cout << endl;

    // Bottom View
    cout << "Printing the bottom view of the tree: " << endl;
    vector<int> bottom = bottomview(root);
    for (int val : bottom) {
        cout << val << " ";
    }
    cout << endl;

    // Left View
    cout << "Printing the left view of the tree: " << endl;
    vector<int> left = leftView(root);
    for (int val : left) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
