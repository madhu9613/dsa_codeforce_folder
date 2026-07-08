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


// void solve() {
//     int n,k;cin>>n>>k;
//     vi a(n);
//     vi pos(n+1);
//     vi L(n),R(n);
//     vi ans(n,0);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         pos[a[i]]=i;
//         L[i]=i-1;
//         R[i]=i+1;
//     }
//     int team=1;
//     int need=n;
//     while(need>0){
//         int idx=pos[need];
//         need--;
//         if(ans[idx]!=0){
//             continue;
//         }
//         int left=idx;
//         int cnt=k;
//         while(cnt && L[left]!=-1){
//             left=L[left];
//             cnt--;
//         }
//         int right=idx;
//         cnt=k;
//         while(cnt && R[right]!=n){
//             right=R[right];
//             cnt--;
//         }

//         int i=left;
//         bool done=false;
//         while(!done){
//             ans[i]=team;
//             if(i==right) {
//                 done =true;
//             }
//             i=R[i];
//         }

//         int l1=L[left];
//         int r1=R[right];
//         if(l1!=-1){
//             R[l1]=r1;
//         }
//         if(r1!=n){
//             L[r1]=l1;
//         }

//         team=3-team;
//     }

//     for(int i=0;i<n;i++){
//         cout<<ans[i];
//     }
//     cout<<endl;
// }

// solving using set;

void solve(){
    int n,k;cin>>n>>k;
    vector<pair<int,int>>v(n);
    set<int>alive;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v[i]={x,i};
       alive.insert(i);
    }
    sort(rall(v));
    vi ans(n,0);
    int t=1;
    for(auto &[val,idx]:v){
        if(ans[idx]!=0){
            continue;
        }
        vi remove;

        auto it=alive.find(idx);
        auto left_it=it;
        for(int i=0;i<k;i++){
            if(left_it==alive.begin()){
                break;
            }
            left_it--;

            remove.push_back(*left_it);
        }

        remove.push_back(idx);
        auto right_it=it;
        for(int i=0;i<k;i++){
            right_it++;
            if(right_it==alive.end()){
                break;
            }
            remove.push_back(*right_it);
        }

        for(int i:remove){
            ans[i]=t;
            alive.erase(i);
        }
        t=3-t;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
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