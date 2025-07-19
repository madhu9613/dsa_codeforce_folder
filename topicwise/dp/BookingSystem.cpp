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

void solve()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> req; 
    for (int i = 0; i < n; i++) {
        int c, p;
        cin >> c >> p;
        req.push_back({p, c, i + 1}); 
    }

    int k;
    cin >> k;
    vector<pair<int, int>> table; // (capacity, index)
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        table.push_back({c, i + 1});
    }

    sort(all(req), greater<>()); // sort by descending pay
    sort(all(table));            
    vector<bool> used(k, false);
    vector<pair<int, int>> result;
    int total = 0;

    for (auto [pay, size, req_id] : req) {
        for (int i = 0; i < k; i++) {
            if (!used[i] && table[i].first >= size) {
                used[i] = true;
                result.push_back({req_id, table[i].second});
                total += pay;
                break;
            }
        }
    }

    cout << result.size() << " " << total << endl;
    for (auto [req_id, table_id] : result) {
        cout << req_id << " " << table_id << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
