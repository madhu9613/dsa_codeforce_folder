#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Trie Node
class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEnd = false;
    }
};

// Trie with insert and search
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode* node, string prefix, vector<string>& result) {
        if (node->isEnd) {
            result.push_back(prefix);
        }
        for (auto& pair : node->children) {
            dfs(pair.second, prefix + pair.first, result);
        }
    }

    vector<string> getSuggestions(string prefix) {
        TrieNode* node = root;
        vector<string> result;

        // Traverse to the node matching the prefix
        for (char ch : prefix) {
            if (!node->children.count(ch)) {
                return {}; // No such prefix
            }
            node = node->children[ch];
        }

        // DFS from that node
        dfs(node, prefix, result);
        sort(result.begin(), result.end()); // optional: sorted output
        return result;
    }
};

// Driver
vector<vector<string>> phoneDirectory(vector<string>& contacts, string query) {
    Trie trie;
    for (const string& contact : contacts) {
        trie.insert(contact);
    }

    vector<vector<string>> output;
    string prefix = "";

    for (char ch : query) {
        prefix += ch;
        vector<string> matches = trie.getSuggestions(prefix);
        if (matches.empty()) {
            output.push_back({"0"}); // or empty vector if no matches
        } else {
            output.push_back(matches);
        }
    }

    return output;
}

int main() {
    // cod coding codding code coly

    vector<string> contacts = {"cod", "coding", "codding", "code"};
    string query = "coding";

    vector<vector<string>> result = phoneDirectory(contacts, query);

    int step = 1;
    for (auto& suggestions : result) {
        cout << "Step " << step++ << ": ";
        for (const string& name : suggestions) {
            cout << name << " ";
        }
        cout << endl;
    }

    return 0;
}
