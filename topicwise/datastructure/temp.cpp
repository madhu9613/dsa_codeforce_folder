#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // STEP 1: find all bad segments using cur/nxt
    vector<vector<int>> bad_end(n);
    vector<pair<ll, int>> cur, nxt;

    for (int r = 0; r < n; r++)
    {
        nxt.clear();
        nxt.push_back({a[r], r});

        for (auto &p : cur)
        {
            ll g = gcd(p.first, a[r]);
            if (nxt.back().first == g)
                nxt.back().second = min(nxt.back().second, p.second);
            else
                nxt.push_back({g, p.second});
        }
        cur = nxt;

        for (auto &p : cur)
        {
            ll g = p.first;
            int l = p.second;
            if (g == r - l + 1)
            {
                bad_end[r].push_back(l);
            }
        }
    }

    // STEP 2: dynamic greedy per prefix
    multiset<int> chosen;                           // chosen points
    priority_queue<pii, vector<pii>, greater<>> pq; // (r, l)

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        // add new bad segments ending at i
        for (int l : bad_end[i])
        {
            pq.push({i, l});
        }

        // remove already covered segments
        while (!pq.empty())
        {
            auto [r, l] = pq.top();

            // check if covered
            auto it = chosen.lower_bound(l);
            if (it != chosen.end() && *it <= r)
            {
                pq.pop(); // already covered
            }
            else
            {
                // need to choose r
                chosen.insert(r);
                pq.pop();
            }
        }

        ans[i] = chosen.size();
    }

    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}
