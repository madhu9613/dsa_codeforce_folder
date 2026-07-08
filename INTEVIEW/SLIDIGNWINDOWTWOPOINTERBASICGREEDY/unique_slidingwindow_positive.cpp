//all are positive integers so 

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
    vi nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
        int maxsum=0;
        unordered_set<int>st;
        int l=0;
        int sum=0;
        for(int r=0;r<n;r++){
              

            while(st.count(nums[r])){
                sum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            st.insert(nums[r]);
            sum+=nums[r];
            maxsum=max(maxsum,sum);
        }
    cout<<maxsum;
}

//exect(k)=atmost(k)-atmost(k-1)

int atMostK(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    int l = 0;
    int count = 0;

    for (int r = 0; r < nums.size(); r++)
    {
        freq[nums[r]]++;

        while (freq.size() > k)
        {
            freq[nums[l]]--;
            if (freq[nums[l]] == 0)
                freq.erase(nums[l]);
            l++;
        }

        count += (r - l + 1);
    }
    return count;
}

int exactlyK(vector<int> &nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}


void solve_exectly_k_duplicate_allowed(){
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   
    unordered_map<int,int>freq;
    int l=0,maxisum=0,cs=0;
    for(int r=0;r<n;r++){
        freq[a[r]]++;
        cs+=a[r];
        while(freq.size()>k){
            freq[a[l]]--;
            cs-=a[l];
            if(freq[a[l]]==0){
                freq.erase(a[l]);
            }
            l++;
        }

        if(freq.size()==k){
            maxisum=max(maxisum,cs);
        }
    }

    cout<<maxisum<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}