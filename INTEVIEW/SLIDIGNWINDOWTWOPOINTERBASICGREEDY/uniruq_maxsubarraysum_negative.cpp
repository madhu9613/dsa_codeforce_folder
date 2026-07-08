//important adv level->
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
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll pref(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1]=pref[i]+a[i];
    }
    unordered_map<int,int>last;
    deque<int>dq;
    int l=0;
    ll maxsum=0;
    for(int r=0;r<n;r++){
        if(last.count(a[r]) && last[a[r]]>=l){
            l=last[a[r]]+1;
        }
        last[a[r]]=r;
        while(!dq.empty() && dq.front()<l){
            dq.pop_front();
        }
        while(!dq.empty() && pref[dq.back()]>=pref[r]){
            dq.pop_back();
        }

        dq.push_back(r);

        ll cur=pref[r+1]-pref[dq.front()];
        maxsum=max(maxsum,cur);
    }

    cout<<maxsum<<endl;

}


void solve_maximum_sum_exectlyK(){
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll pref(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1]=pref[i]+a[i];
    }

    unordered_map<int,int>freqk,freqk1;
    int leftk=0,leftk1=0;
    int added=0;
    deque<int>dq;
    ll maxsum=-INF;

    for(int r=0;r<n;r++){
        freqk[a[r]]++;
        while(freqk.size()>k){
            
            freqk[a[leftk]]--;

            if(freqk[a[leftk]]==0){
                freqk.erase(a[leftk]);
            }
            leftk++;
        }

        freqk1[a[r]]++;
        while (freqk1.size() > k-1)
        {
            freqk1[a[leftk1]]--;

            if (freqk[a[leftk1]] == 0)
            {
                freqk1.erase(a[leftk1]);
            }
            leftk1++;
        }

        if(freqk.size()==k){
            while(added<leftk1){
                while(!dq.empty() && pref[dq.back()]>=pref[added]){
                    dq.pop_back();
                }
                dq.push_back(added);
                added++;
            }
            while(!dq.empty() && dq.front()<leftk){
                dq.pop_front();
            }

            if(!dq.empty()){
                ll cur=pref[r+1]-pref[dq.front()];
                maxsum=max(maxsum,cur);
         }

        }
    }

    cout << (maxsum == LLONG_MIN ? 0 : maxsum) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}