// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define vi vector<int>
// #define vll vector<ll>
// #define max3(a, b, c) max(max(a, b), c)
// #define max4(a, b, c, d) max(max(a, b), max(c, d))
// #define pii pair<int,int>
// #define all(x) (x).begin(), (x).end()
// #define endl '\n'

// ll gcd(ll a, ll b)
// {
//  return b == 0 ? a : gcd(b, a % b);
// }
// const int MOD = 1e9 + 7;
// const int INF = INT_MAX;

// void solve() {

//     int n;cin>>n;
//     vll x(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i];
//     }
//     sort(all(x));
//     int q;cin>>q;
//     while (q--)
//     {
//         ll m;cin>>m;
//         auto it=upper_bound(all(x),m);
//         if(it==x.begin())
//         {
//            cout<<0<<endl;
//         }
//         else {
          
//             int idx=it-x.begin();
//             cout<<idx<<endl;
//         }
//     }
    
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t = 1;
//     while (t--) solve();
//     return 0;
// }

// solving via dp learning 

#include <bits/stdc++.h>
using namespace std;

const int MAX_PRICE = 100000;

int main() {
    int n;
    cin >> n;
    vector<int> freq(MAX_PRICE + 1, 0);

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x <= MAX_PRICE) freq[x]++;
    }

    vector<int> dp(MAX_PRICE + 1, 0);
    for(int i = 1; i <= MAX_PRICE; ++i) {
        dp[i] = dp[i - 1] + freq[i];
    }

    int q;
    cin >> q;
    while(q--) {
        int mi;
        cin >> mi;
        if(mi > MAX_PRICE) mi = MAX_PRICE;
        cout << dp[mi] << "\n";
    }

    return 0;
}
