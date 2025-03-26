#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
void deletemid(stack <int> &st,int curr,int mid)
{
 if(curr==mid)
 {
    st.pop();
    return;
 }
 int topelemet=st.top();
 st.pop();

 deletemid(st,curr+1,mid);
 st.push(topelemet);
}

int main()
{
    stack <int> st;
   string input;
   getline(cin,input);
   stringstream ss(input);
   int data;
   while(ss>>data)
   {
    st.push(data);
   }
    int mid=st.size()/2;
    deletemid(st,0,mid);
    cout<<"after deleting the stack is:\n";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}