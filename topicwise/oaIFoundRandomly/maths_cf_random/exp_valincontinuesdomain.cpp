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

// let p(t)=probability for a number to be less that or equal to t; // its not discreat;
// F(t) = P(X<=t)
// E[X]=∫​(1−F(t))dt​. from 0 to 1;
//


typedef vector<long double>poly;
poly add(const poly&a ,const poly &b){
    poly res(max(a.size(),b.size()),0);
    for(size_t i=0;i<a.size();i++){
        res[i]+=a[i];
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        res[i] += b[i];
    }
    return res;
}
poly multiply(const poly &a,const poly &b){
    if(a.empty() || b.empty()){
        return {};
    }
    poly res(a.size()+b.size()-1,0.0);
    for(size_t i=0;i<a.size();i++){
        for(size_t j=0;j<b.size();j++){
            res[i+j]+=a[i]*b[j];
        }
    }
    return res;
}
poly parse(const string &s,int &idx){
    char c=s[idx++];
    if(c=='x'){
        return {0.0,1.0};
    }
    else if(c=='M'){
        poly left=parse(s,idx);
        poly right=parse(s,idx);
        return multiply(left,right);
    }
    else if(c=='m'){
        poly left=parse(s,idx);
        poly right=parse(s,idx);
        poly sum=add(left,right);
        poly prod=multiply(left,right);
        poly res(max(sum.size(), prod.size()), 0.0);
    for(size_t i=0;i<sum.size();i++){
        res[i]+=sum[i];
    }
    for (size_t i = 0; i < prod.size(); ++i)
        res[i] -= prod[i];

    return res;
    }

    return {};
  
}
void solve() {

    string s;cin>>s;
    int idx=0;
    poly cdf=parse(s,idx);
    long double I=0.0;
    for(size_t i=0;i<cdf.size();i++){
        I+=cdf[i]/(i+1.0);
    }
    cout<<fixed<<setprecision(6)<<1.0-I<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}