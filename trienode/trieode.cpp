#include<bits/stdc++.h>
using namespace std;
class trinode{
public:
int data;
trinode* children[26];
bool isend;
trinode(int data)
{
    this->data=data;
    for(int i=0;i<26;i++)
    {
        children[i]=nullptr;
    }
    isend=false;

}
};
class trie{
void insert(trinode* root, string & word)
{
    if(word.length(==0))
    {
        root->isend=true;
        return 0;
    }
    int index=tolower(word[0])-'a'; //converting  to indexing
    trinode* child;
    if(root->children[index]!=NULL)
    {
        child=root->children[index];
    }
    else{
        child=new trinode(word[0]);
        root->children[index]=child;
    }

    insert(root,word.substr(1));

}
bool searchword(trinode* root, &word)
{
    if(word.length()==0)
    {
        return root->isend;
    }

    int index=tolower(word[0])-'a';
    trinode* child;
    if(root->children[index]!=NULL)
    {
        child=root->children[index];
    }
    else{
        return false;

    }

    return searchword(root,word.substr(1))
}
void removeword(trinode* root,string &word)

{
    if(word.length()==0)
    {
        root->isend=false;
        return;
    }
    trinode* child;
    int index=tolower(word[0])-'a';
    if(root->children[index]!=NULL)
    {
        child=root->children[index];
    }
    else{
        return;
    }
    return removeword(root,word.substr(1));
}
public:


};
int main()
{
    return 0;
}