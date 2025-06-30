#include <bits/stdc++.h>
using namespace std;

void sve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> num(m);
    for (int i = 0; i < m; ++i) {
        cin >> num[i];
    }
    
    sort(num.begin(), num.end());
    
    long long ANS = 0;
    for (int L = 1; L < n; ++L) {
        int R = n - L;
        int max_LR = max(L, R);
        
        auto itL = lower_bound(num.begin(), num.end(), L);
        int cL = num.end() - itL;
        
        auto itR = lower_bound(num.begin(), num.end(), R);
        int cR = num.end() - itR;
        
        auto itSame = lower_bound(num.begin(), num.end(), max_LR);
        int same = num.end() - itSame;
        
        ANS += 1LL * cL * cR - same;
    }
    
    cout << ANS << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    
    while (tt--) {
        sve();
    }
    
    return 0;
}