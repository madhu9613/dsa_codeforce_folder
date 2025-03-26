/*Given an array arr[]  and a positive integer k, find the first negative integer for 
each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.*/

#include <iostream>
#include <vector>
#include<queue>
using namespace std;
void solve(vector<int> v,vector<int> &result,int n,int k)
{
    deque<int> dq;
 //process first k element and stor its data
 for(int i=0;i<k;i++)
 {
    if(v[i]<0)

    {
        dq.push_back(i);
    }
 }
 //store answer
 if(!dq.empty())
 {
    result.push_back(v[dq.front()]);
 }
 else{
    result.push_back(0);

 }

 for(int i=k;i<n;i++)
 {
    if(!dq.empty() && i-dq.front()>=k)
    {
   dq.pop_front();
    }
    if(v[i]<0)
    {
        dq.push_back(i);
    }
     if(!dq.empty())
 {
    result.push_back(v[dq.front()]);
 }
 else{
    result.push_back(0);

 }

 }
}

int main() {
    int n, k;
    vector<int> v;
    cin >> n >> k;
    vector<int> result;
    int data;

    // Input the array
    for (int i = 0; i < n; i++) {
        cin >> data;
        v.push_back(data);
    }

   
// solvebruteforce(v,result,n,k);
    // Output the results
    solve(v,result,n,k);
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
