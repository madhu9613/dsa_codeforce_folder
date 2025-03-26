#include <iostream>
#include <queue>
#include <unistd.h> // For sleep function
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

node* buildtree(node* root) {
    cout << "Enter the data for node:\n";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for left of " << data << ":\n";
    root->left = buildtree(root->left);
    cout << "Enter data for right of " << data << ":\n";
    root->right = buildtree(root->right);
    
    return root;
}

void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for level end

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl; // New line at the end of each level
            if (!q.empty()) {
                q.push(NULL); // Add marker for next level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    node* root = NULL;
    root = buildtree(root);

    // Pause for 5 seconds before clearing the screen
    sleep(5);

    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux/macOS
    #endif

    cout << "Level order traversal is:\n";
    levelOrderTraversal(root);

    return 0;
}
