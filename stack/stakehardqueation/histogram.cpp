
#include <iostream>
#include <vector>
#include <sstream>
#include<stack>
using namespace std;
vector<int> nextsmaller(vector<int> &arr)
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

vector<int> prevsmaller(vector<int> &arr)
{
    stack<int> s;
    vector<int> ans(arr.size());
    s.push(-1);
    int n=arr.size();
    for(int j=0;j<n;j++)
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
int maxarea(vector<int> v)
{
    int n=v.size();
   stack<int> s;
   vector<int> next(n);
   vector<int> prev(n);
   s.push(-1);
   next=nextsmaller(v);


}
int main() {
    string input;
    getline(cin, input);
    vector<int> v;
    vector<int> result;
    stringstream ss(input);
    int data;

  
    while (ss >> data) {
        v.push_back(data);
    }
    return 0;;
}