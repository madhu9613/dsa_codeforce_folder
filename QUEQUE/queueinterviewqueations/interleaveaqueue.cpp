#include<iostream>
#include<queue>
#include<sstream>

using namespace std;
void interleave(queue<int> &q)
{
     
}
int main()
{
    queue<int>q;
    string input;
    getline(cin,input);
    int data;
    stringstream ss(input);

    while(ss>>data)
    {
        q.push(data);

    }
    interleave(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
        return 0;
}