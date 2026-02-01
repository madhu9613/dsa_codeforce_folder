#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 105;
const int K = 15;
const int MAXV = 5000000;

int n;
ll a[MAXN];
ll highp[MAXN], lowp[MAXN];

map<int, int> go[MAXV];
int stored[MAXV];
int nodes;


int get_next(int v, int x)
{
    if (!go[v].count(x))
        go[v][x] = nodes++;
    return go[v][x];
}

void trie_insert(const vector<int> &diff, int x)
{
    int v = 0;
    for (int d : diff)
        v = get_next(v, d);
    stored[v] = x;
}

int trie_find(const vector<int> &diff)
{
    int v = 0;
    for (int d : diff)
    {
        if (!go[v].count(d))
            return -1;
        v = go[v][d];
    }
    return stored[v];
}


vector<int> get_diff(ll arr[], int x)
{
    vector<int> cnt(n);
    for (int i = 0; i < n; i++)
        cnt[i] = __builtin_popcountll(arr[i] ^ x);

    vector<int> diff(n - 1);
    for (int i = 1; i < n; i++)
        diff[i - 1] = cnt[i] - cnt[0];

    return diff;
}


void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        highp[i] = a[i] >> K;
        lowp[i] = a[i] & ((1LL << K) - 1);
    }

    nodes = 1;
    for (int i = 0; i < MAXV; i++)
    {
        go[i].clear();
        stored[i] = -1;
    }

    for (int x = 0; x < (1 << K); x++)
    {
        vector<int> diff = get_diff(highp, x);
        trie_insert(diff, x);
    }

    // search using low half
    for (int x = 0; x < (1 << K); x++)
    {
        vector<int> diff = get_diff(lowp, x);
        for (int &v : diff)
            v = -v;

        int hx = trie_find(diff);
        if (hx != -1)
        {
            ll ans = (ll(hx) << K) ^ x;
            cout << ans << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
