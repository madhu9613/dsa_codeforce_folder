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
const int MAXN =1e6 + 5;

ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll fact[MAXN], invFact[MAXN];
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modinv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

vector<int> primes;
bool isPrime[MAXN];
void sieve(int n) {
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int phi[MAXN];
void sievePhi(int n) {
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

using Matrix = vector<vector<ll>>;
Matrix matMul(Matrix A, Matrix B) {
    int rA = A.size(), cA = A[0].size(), cB = B[0].size();
    Matrix C(rA, vector<ll>(cB, 0));
    for (int i = 0; i < rA; i++) {
        for (int k = 0; k < cA; k++) {
            for (int j = 0; j < cB; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matPow(Matrix A, ll p) {
    int n = A.size();
    Matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = matMul(res, A);
        A = matMul(A, A);
        p >>= 1;
    }
    return res;
}

int L[MAXN];
vi dists[MAXN];
vll pref[MAXN];
int n,m;

ll get_subtree(int u,ll H){
    if(H<0 || u>n){
        return 0;
    }
    auto it=upper_bound(all(dists[u]),H);
    if(it==dists[u].begin()){
        return 0;
    }
    int cnt=distance(dists[u].begin(),it);

    ll sum_dist=pref[u][cnt-1];
    return 1LL*cnt*H-sum_dist;
}

void solve() {

    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>L[i];
    }

    for(int i=n;i>=1;i--){
        dists[i].push_back(0);// dist[u]:u to u is zero
        int left=2*i;
        int right=2*i+1;
        int p_left=0,p_right=0;
        int sz_left=(left<=n)?dists[left].size():0;
        int sz_right=(right<=n)?dists[right].size():0;
        while(p_left<sz_left || p_right<sz_right){
            if(p_left==sz_left){
                dists[i].push_back(dists[right][p_right++]+L[right]);
            }
            else if(p_right==sz_right){
                dists[i].push_back(dists[left][p_left++]+L[left]);
            }else{
                int l=dists[left][p_left]+L[left];
                int r=dists[right][p_right]+L[right];
                if(l<r){
                    dists[i].push_back(l);
                    p_left++;
                }else{
                    dists[i].push_back(r);
                    p_right++;
                }
            }
        }

        int N=dists[i].size();

        pref[i].resize(N);
        ll csum=0;
        for(int j=0;j<N;j++){

            csum+=dists[i][j];
            pref[i][j]=csum;
        }
    }

    while(m--){
        int A;
        ll H;
        cin>>A>>H;
        ll total_ans=get_subtree(A,H);
        int cur=A;
        ll D_p=0;
        while(cur>1){
            int p=cur/2;
            D_p += L[cur];
            ll remaining=H-D_p;
            if(remaining>=0){
                total_ans+=remaining;
                int sibling=(cur%2==0)?(cur+1):(cur-1);
                if(sibling<=n){
                    ll H_for_sibling=remaining-L[sibling];
                    if(H_for_sibling>=0){
                        total_ans+=get_subtree(sibling,H_for_sibling);
                    }
                }
            }
            else{
                break;
            }

            cur=p;
        }

        cout<<total_ans<<endl;

    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}