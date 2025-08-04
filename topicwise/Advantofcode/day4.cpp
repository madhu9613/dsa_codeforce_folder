#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
vector<string>grid;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int n,m;
string target="XMAS";

bool valid(int x,int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool check(int i, int j, int d) {
    for (int k = 0; k < 4; ++k) {
        int ni = i + dx[d] * k;
        int nj = j + dy[d] * k;
        if (!valid(ni, nj) || grid[ni][nj] != target[k])
            return false;
    }
    return true;
}
void solve() {
    string line;
    while (cin>>line)
    {
       grid.pb(line);
    }
 n=grid.size();
 m=grid[0].size();
 if(n==0)
 {
    cout<<0<<endl;
    return ;
 }

 int c=0;
 for(int i=0;i<n;++i)
 {
    for(int j=0;j<m;++j)
    {
      for(int d=0;d<8;++d)
      {
        if(check(i,j,d))
        {
            c++;
        }
      }
    }
 }

 cout<<c<<endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
  
    while (t--) solve();
    return 0;
}