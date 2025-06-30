#include <bits/stdc++.h>
using namespace std;

const long long MAX_STRIP = 1e15;

struct State {
    long long pos;
    int dir;
    int mod;

    bool operator<(const State& other) const {
        return tie(pos, dir, mod) < tie(other.pos, other.dir, other.mod);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> p(n);
        vector<int> d(n);
        map<long long, int> delays_dict;

        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
            delays_dict[p[i]] = d[i];
        }

        int q;
        cin >> q;
        vector<long long> queries(q);
        for (int i = 0; i < q; ++i) cin >> queries[i];

        sort(p.begin(), p.end());

        set<State> states;
        for (long long pos : p) {
            for (int dir : {1, -1}) {
                for (int m = 0; m < k; ++m) {
                    states.insert({pos, dir, m});
                }
            }
        }

        map<State, State> next_state_map;
        map<State, bool> res;
        for (const auto& state : states) {
            long long pos = state.pos;
            int dir = state.dir;
            int mod_val = state.mod;

            int new_dir = (mod_val == delays_dict[pos]) ? -dir : dir;
            long long new_pos0 = pos + new_dir;

            if (new_pos0 < 1 || new_pos0 > MAX_STRIP) {
                res[state] = true; // can exit
                continue;
            }

            long long next_p;
            long long distance;
            bool can_move = false;

            if (new_dir == 1) {
                auto it = lower_bound(p.begin(), p.end(), new_pos0);
                if (it != p.end()) {
                    next_p = *it;
                    distance = next_p - new_pos0;
                    can_move = true;
                }
            } else {
                auto it = upper_bound(p.begin(), p.end(), new_pos0);
                if (it != p.begin()) {
                    --it;
                    next_p = *it;
                    distance = new_pos0 - next_p;
                    can_move = true;
                }
            }

            if (!can_move) {
                res[state] = true; // can exit
                continue;
            }

            long long total_time = 1 + distance;
            int mod_next = (mod_val + total_time) % k;
            next_state_map[state] = {next_p, new_dir, mod_next};
        }

        map<State, vector<State>> rev_graph;
        deque<State> qdeque;

        for (const auto& [state, next_state] : next_state_map) {
            if (res.count(state)) {
                qdeque.push_back(state);
            } else {
                rev_graph[next_state].push_back(state);
            }
        }

        while (!qdeque.empty()) {
            State s = qdeque.front();
            qdeque.pop_front();
            for (auto& prev : rev_graph[s]) {
                if (!res[prev]) {
                    res[prev] = true;
                    qdeque.push_back(prev);
                }
            }
        }

        for (long long a_i : queries) {
            auto it = lower_bound(p.begin(), p.end(), a_i);
            if (it == p.end()) {
                cout << "YES\n";
                continue;
            }
            long long p0 = *it;
            long long time0 = (p0 == a_i) ? 0 : (p0 - a_i);
            int mod0 = time0 % k;
            State initial = {p0, 1, mod0};

            if (res.count(initial) && res[initial]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
