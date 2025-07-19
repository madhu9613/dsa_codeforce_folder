// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
int n,k;cin>>n>>k;
ll ans=0;
string s;cin>>s;
unordered_set<char>icantype;
for(int i=0;i<k;i++)
{
    char c;cin>>c;icantype.insert(c);
}
int l=0;
int len=0;
for(int r=0;r<n;r++)
{
    if(!icantype.count(s[r]))
    {
     
       l=r+1;
       ans+=(len)*(len+1)/2;
         len=0;
    }

    len++;
}
len--;
ans+=(len)*(len+1)/2;
cout<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}