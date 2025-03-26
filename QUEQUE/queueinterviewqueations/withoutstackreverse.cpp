#include<iostream>
#include<queue>
#include<sstream>
using namespace std;
void reversequeue(queue<int> &q)
{
    if(q.empty())

    {
        return;
    }
    //first element
    int num=q.front();
    q.pop(); //delete front
    reversequeue(q);//recursive call;
    q.push(num);

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