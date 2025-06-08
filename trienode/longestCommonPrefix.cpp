#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Trie Node Definition
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

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
        node->isEndOfWord = true;
    }

    string longestCommonPrefix() {
        string prefix;
        TrieNode* node = root;
        while (node && node->children.size() == 1 && !node->isEndOfWord) {
            auto it = node->children.begin();
            prefix += it->first;
            node = it->second;
        }
        return prefix;
    }
};

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    Trie trie;
    for (const string& word : strs) {
        trie.insert(word);
    }

    return trie.longestCommonPrefix();
}

int main() {
    vector<string> strs = {"code", "coder", "codechef","coderunner"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}
