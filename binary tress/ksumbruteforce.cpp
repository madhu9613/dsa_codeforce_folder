#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int x) : data(x), left(NULL), right(NULL) {}
};

// Helper function to check all subpaths ending at the current node


void ksum(node* root, int k, unordered_map<int, int>& prefixSum, int currSum, vector<vector<int>>& result, vector<int>& path) {
    if (!root) return;

    currSum += root->data;
    path.push_back(root->data);

    if (prefixSum.find(currSum - k) != prefixSum.end()) {
        result.push_back(vector<int>(path.end() - prefixSum[currSum - k], path.end()));
    }

    prefixSum[currSum]++;
    
    ksum(root->left, k, prefixSum, currSum, result, path);
    ksum(root->right, k, prefixSum, currSum, result, path);

    prefixSum[currSum]--;
    path.pop_back();
}

void findKSumPaths(node* root, int k, vector<vector<int>>& result) {
    unordered_map<int, int> prefixSum;
    vector<int> path;
    prefixSum[0] = 1;  // To handle cases where root-to-node sum is exactly k
    ksum(root, k, prefixSum, 0, result, path);
}

// Driver function
int main() {
    node* root = new node(1);
    root->left = new node(3);
    root->right = new node(-1);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->left->right->left = new node(1);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right->right = new node(6);

    int k = 5;
    vector<vector<int>> result;
     findKSumPaths(root, k,result);

    cout << "Paths with sum " << k << ":\n";
    for (auto& p : result) {
        cout << "[ ";
        for (int num : p) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
