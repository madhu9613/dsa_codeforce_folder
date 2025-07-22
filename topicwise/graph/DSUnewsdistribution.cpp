// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
vi par, dsu_size;

int find(int x)
{
    if (par[x] != x)
    {
        par[x] = find(par[x]);
    }
    return par[x];
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (dsu_size[a] < dsu_size[b])
        {
            swap(a, b);
        }
        par[b] = a;
        dsu_size[a] += dsu_size[b];
    }
}

int n, m;
void solve()
{

    cin >> n >> m;
    par.resize(n + 1);
    dsu_size.resize(n + 1, 1);

    for (int i = 1; i <= n; i++)
        par[i] = i;

    while (m--)
    {
        int k;
        cin >> k;
        vi f(k);
        for (int i = 0; i < k; i++)
        {
            cin >> f[i];
        }
        for (int i = 0; i < k - 1; i++)
        {
            unite(f[i], f[i + 1]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<dsu_size[find(i)]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}