/*
    QUEATION NO 2
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<1<<endl;
        }
        else{
        int op=2;
        int ul=4;
        while(n>ul)
        {
               op++;
               ul=2*ul+2;

        }
        cout<<op<<endl;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
