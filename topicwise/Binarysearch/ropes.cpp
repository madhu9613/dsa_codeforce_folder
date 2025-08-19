#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve() {
    int n, k;
    cin >> n >> k;
    vll a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double l = 0.0, r = 1e7; 
    double ans = 0.0;
    double eps = 1e-6;

     while (r - l > eps) {
        double m = (l + r) / 2.0;

        int pieces = 0;
        for(int i = 0; i < n; i++) {
            pieces += (int)(a[i] / m);  
        }

        if(pieces >= k) {   
            ans = m;        
            l = m;         
        } else {
            r = m;          
        }
    }
  

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
