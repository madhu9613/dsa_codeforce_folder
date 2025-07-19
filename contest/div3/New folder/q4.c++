#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

struct node {
    int l, r, real;
    node(int l=0,int r=0,int real=0): l(l),r(r),real(real) {}
};


int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
       ll k;
        cin >> n >> k;
        vector<node> casinos(n);
        for (int i = 0; i < n; i++) {
          int l,r,real;cin>>l>>r>>real;
         casinos[i]=node(l,r,real);
        }

        sort(casinos.begin(), casinos.end(), [](node &a, node &b) {
            return a.l < b.l;
        });

        int i = 0;
        priority_queue<int> pq;

        while (true) {
            while (i < n && casinos[i].l <= k) {
                if (casinos[i].r >= k) {
                    pq.push(casinos[i].real);
                }
                i++;
            }

            if (pq.empty()) break;

            k = max(k, 1LL * pq.top());  
            pq.pop();
        }

        cout << k << '\n';
    }
    return 0;
}
