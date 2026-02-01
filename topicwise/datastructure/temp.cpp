#include <bits/stdc++.h>
using namespace std;

const int MAXF = 450; // maximum possible frequency
const int BSZ = 20;   // block size for freq sqrt-decomp

/* ---------------- DATA STRUCTURES ---------------- */

struct Query
{
    int l, r, t, id;
};

struct Update
{
    int pos, oldVal, newVal;
};

int n, q;
vector<int> a; // current array
vector<Query> queries;
vector<Update> updates;
int ans[100005];

/* ---------------- MO STATE ---------------- */

int cnt[200005];                // cnt[value] in current range
int freq[MAXF + 5];             // freq[f] = how many values appear f times
int blockCnt[(MAXF / BSZ) + 5]; // how many filled in each freq block

int curL = 0, curR = -1, curT = 0;

/* ---------------- ADD / REMOVE ---------------- */

inline void add(int pos)
{
    int x = a[pos];
    int old = cnt[x];
    if (old > 0)
    {
        freq[old]--;
        blockCnt[old / BSZ]--;
    }
    cnt[x]++;
    freq[old + 1]++;
    blockCnt[(old + 1) / BSZ]++;
}

inline void remove_(int pos)
{
    int x = a[pos];
    int old = cnt[x];
    freq[old]--;
    blockCnt[old / BSZ]--;
    cnt[x]--;
    if (cnt[x] > 0)
    {
        freq[old - 1]++;
        blockCnt[(old - 1) / BSZ]++;
    }
}

/* ---------------- APPLY / ROLLBACK UPDATE ---------------- */

inline void applyUpdate(int id)
{
    auto &u = updates[id];
    if (curL <= u.pos && u.pos <= curR)
    {
        remove_(u.pos);
        a[u.pos] = u.newVal;
        add(u.pos);
    }
    else
    {
        a[u.pos] = u.newVal;
    }
}

inline void rollbackUpdate(int id)
{
    auto &u = updates[id];
    if (curL <= u.pos && u.pos <= curR)
    {
        remove_(u.pos);
        a[u.pos] = u.oldVal;
        add(u.pos);
    }
    else
    {
        a[u.pos] = u.oldVal;
    }
}

/* ---------------- MEX QUERY ---------------- */

inline int getMex()
{
    for (int b = 0; b <= MAXF / BSZ; b++)
    {
        if (blockCnt[b] < BSZ)
        {
            for (int i = b * BSZ; i < (b + 1) * BSZ; i++)
            {
                if (i >= 1 && freq[i] == 0)
                    return i;
            }
        }
    }
    return MAXF + 1;
}

/* ---------------- MO SORT ---------------- */

int BLOCK;

bool cmp(const Query &a, const Query &b)
{
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l < b.l;
    if (a.r / BLOCK != b.r / BLOCK)
        return a.r < b.r;
    return a.t < b.t;
}

/* ---------------- MAIN ---------------- */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    BLOCK = pow(n, 2.0 / 3);

    int time = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r;
            cin >> l >> r;
            queries.push_back({l - 1, r - 1, time, (int)queries.size()});
        }
        else
        {
            int p, x;
            cin >> p >> x;
            --p;
            updates.push_back({p, a[p], x});
            a[p] = x;
            time++;
        }
    }

    // restore array
    for (auto &u : updates)
        a[u.pos] = u.oldVal;

    sort(queries.begin(), queries.end(), cmp);

    for (auto &q : queries)
    {
        while (curT < q.t)
            applyUpdate(curT++);
        while (curT > q.t)
            rollbackUpdate(--curT);
        while (curL > q.l)
            add(--curL);
        while (curR < q.r)
            add(++curR);
        while (curL < q.l)
            remove_(curL++);
        while (curR > q.r)
            remove_(curR--);

        ans[q.id] = getMex();
    }

    for (int i = 0; i < (int)queries.size(); i++)
        cout << ans[i] << "\n";
}
