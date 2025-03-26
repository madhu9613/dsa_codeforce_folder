
/*reverse a queue
*/
#include<iostream>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;
void reversequeue(queue<int> &q)

{
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
int main()

{
    queue<int> q;
string input;
getline(cin,input);
stringstream ss(input);
int data;
while(ss>>data)
{
q.push(data);
}
reversequeue(q);
cout<<"reversed queue is\n";
while(!q.empty())
{
    cout<<q.front()<<" ";
    q.pop();
}
    return 0;
}