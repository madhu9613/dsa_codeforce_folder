#include <iostream>
using namespace std;

class trienode
{
public:
    char data;
    trienode *children[26]; // Store children of each node
    bool isendofword;       // Flag to mark the end of the word

    // Constructor to initialize a Trie node
    trienode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isendofword = false;
    }
};

class trie
{
private:
    void insert(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isendofword = true; // Mark the last node as the end of the word
            return ;
        }

        int index = tolower(word[0]) - 'a';  // Convert to lowercase and find the index
        trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        insert(child, word.substr(1)); // Recursive call with the rest of the word
    }

    bool searchword(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isendofword;
        }

        int index = tolower(word[0]) - 'a'; // Convert to lowercase and find the index
        trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
          return false;   
        }

       return  searchword(child, word.substr(1)); // Recursive call with the rest of the word
    }

    void removeword(trienode* root,string word)
     {
           

        if (word.length() == 0)
        {
            root->isendofword=false;
        }

        int index = tolower(word[0]) - 'a'; // Convert to lowercase and find the index
        trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
          return ;
        }

         removeword(child,word.substr(1));
     }

public:
    trienode *root;

    // Constructor to initialize the root node of the Trie
    trie()
    {
        root = new trienode('\0'); // Create an empty root node
    }

    // Public function to insert a word into the Trie
    void insertword(string word)
    {
        insert(root, word);
    }

    bool search(string word)
    {
        return searchword(root, word);
    }
    void remove(string word)
    {
        removeword(root,word);
    }
};

int main()
{
    trie t;

    t.insertword("madhhujya"); // Insert a word into the Trie
    t.insertword("raj");
    t.insertword("love");
    t.insertword("rajendra");
    t.insertword("love");
    t.insertword("raju");
    t.insertword("long");
    t.insertword("rohit");
    t.insertword("lose");
    t.insertword("rip");
    t.insertword("lead");
    t.insertword("can");
    t.insertword("canva");
    t.insertword("cambrige");
    t.insertword("canada");
    t.insertword("malinga");
    t.insertword("mouse");
    t.insertword("india");
    t.insertword("indunasia");

    
int tt;
cin>>tt;
while(tt--)
{
    
    string input;
    cin>>input;
     if(t.search(input))
    {
        cout<<"word is present";
    }
    else{
        cout<<"not present";
    }
       
}
return 0;
}
