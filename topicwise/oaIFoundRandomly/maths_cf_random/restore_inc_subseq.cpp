#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
 int n;cin>>n;
 vector<string>seq(n);
 for(int i=0;i<n;i++)
 {
    cin>>seq[i];
 }
 string prev="0";
 for(int k=0;k<n;k++){
    string pattern=seq[k];
   if(pattern.length()<prev.length()){
    cout<<"NO"<<endl;
    return ;
   }else if(pattern.length()>prev.length()){
    if(pattern[0]=='?'){
        pattern[0]='1';
    }
    for(int i=1;i<pattern.length();i++){
        
        if(pattern[i]=='?'){
            pattern[i]='0';
        }
    }

    prev=pattern;
    seq[k]=pattern;

   }else{

    //equal  move from right find smallest number greater than prev possible to make ;
    
    string best="";
    int m=pattern.length();
    for(int i=m-1;i>=0;i--){
        bool valid=true;
        string cand="";

        for(int j=0;j<m;j++){
            if(j<i){
                if(pattern[j]=='?'){
                    cand+=prev[j];
                }else if(pattern[j]==prev[j]){
                    cand+=pattern[j];
                }else{
                    valid=false;
                    break;
                }
            }
            else if(j==i){
                if(pattern[j]=='?'){
                    if(prev[j]=='9'){
                        valid=false;
                        break;
                    }
                    cand+=(char)(prev[j]+1);
                }else{
                    if(pattern[j]<=prev[j]){
                        valid=false;
                        break;
                    }
                    cand += pattern[j];
                }
            }else{
                if(pattern[j]=='?'){
                    cand+='0';
                }else{
                    cand+=pattern[j];
                }
            }
        }

        if(valid){
            best=cand;
            break;
        }
    }
    if(best==""){
        cout<<"NO"<<endl;
        return;
    }
    prev=best;
    seq[k]=best;
   }
 }   

 cout<<"YES"<<endl;
 for(auto &s:seq){
    cout<<s<<endl;
 }
 cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}