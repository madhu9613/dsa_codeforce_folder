#include<iostream>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;
vector<int> solve(vector<int> &arr)
{
    stack<int> s;
    vector<int> ans(arr.size());
    s.push(-1);
    int n=arr.size();
    for(int j=n-1;j>=0;j--)
    {
        int curr=arr[j];
      while(s.top()>=curr)
      {
        s.pop();
      }
      ans[j]=s.top();
      s.push(curr);


    }
    return ans;
}
int main()
{ 

string input;
getline(cin,input);

stringstream ss(input);
int data;

vector<int> v;
while(ss>>data)
{
    v.push_back(data);
}
vector<int> result=solve(v);

for(int i:result)
{
    cout<<i<<" ";
}
cout<<endl;


    return 0;
}