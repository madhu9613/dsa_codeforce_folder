#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
void deletemid(stack <int> &st,int mid)
{
   stack <int> temp;
   for(int i=0;i<mid;i++)
   {
    temp.push(st.top());
    st.pop();
   }
   st.pop(); //deleting the middle term
   while(!temp.empty())
   {
    st.push(temp.top());
    temp.pop();
   }
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
    deletemid(st,mid);
    cout<<"after deleting the stack is:\n";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}