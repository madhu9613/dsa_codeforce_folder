#include <iostream>
#include<stack>
#include<sstream>
//LIFO order 
using namespace std;
int main()
{
    stack <int> s;
    string input;
    getline(cin,input);
    stringstream ss(input);
    int data;
    while(ss>>data)
    {
        s.push(data);
    }
    cout<<"size of stack is"<<s.size()<<endl;
    cout<<"top element is "<<s.top()<<" \n";
   while(!s.empty())
   {
    cout<<s.top()<<" ";
    s.pop();
   }
    return 0;
}