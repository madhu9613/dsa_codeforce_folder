#include<iostream>
#include<queue>
#include<sstream>

using namespace std;
int main()
{
    queue<int> q;
string input;
getline(cin,input);
int data;
stringstream ss(input);
while(ss>>data)
{
    q.push(data);
}    

cout<<"size of queue is"<<q.size()<<endl;
cout<<"front element"<<q.front()<<endl;
q.pop();
cout<<"after pop size\n"<<q.size()<<endl;
cout<<"front is "<<q.front();
    return 0;
}
