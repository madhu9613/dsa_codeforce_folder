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
#define ld long double
ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
ld dp[105][105][105];
void solve() {
int R,S,P;cin>>R>>S>>P;
ld pr=0,ps=0,pp=0;
memset(dp, 0, sizeof(dp));

dp[R][S][P]=1;
for(int r=R;r>=0;r--)
{
    for(int s=S;s>=0;s--)
    {
        for(int p=P;p>=0;p--)
        {
          
            ld cur=dp[r][s][p];
            if(cur==0) continue;
            if (s==0 && p==0){pr+=cur; continue;}
            if(r==0 && p==0) {ps+=cur; continue;}
            if(r==0 && s==0) {pp+=cur;continue;}

            ld total=r*s+s*p+r*p;
            if(total==0) continue;

            if(r>0 && s>0) dp[r][s-1][p]+=cur*((ld)(r*s)/total);

            if(s>0 && p>0) dp[r][s][p-1]+=cur*((ld)(s*p)/total);

            if(p>0 && r>0) dp[r-1][s][p]+=cur*((ld)(p*r)/total);
        
        }
    }


}
cout<<fixed<<setprecision(12)<<pr<<" "<<ps<<" "<<pp<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}