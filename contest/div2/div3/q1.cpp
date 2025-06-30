/*

QUEATION NO 1
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {

   int n,a,b;
   cin>>n>>a>>b;
   if(abs(a-b)%2==0 && a!=b)
   {
     cout<<"yes"<<endl;
   }

  else{
    cout<<"no"<<endl;
  }      
}
}
int main() {
   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
