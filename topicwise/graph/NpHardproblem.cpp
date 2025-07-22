// // Author: Madhujya Rajkhowa
// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define endl '\n'

// int n, m;
// vector<vector<int>> adj;
// vector<int> dist, par;
// vector<int> seta, setb;
// set<int> used; // Only track used nodes

// bool detectoddlengthcycle() {
//     dist.assign(n + 1, -1);
//     par.assign(n + 1, -1);
//     seta.clear();
//     setb.clear();

//     for (int start : used) {
//         if (dist[start] != -1) continue;

//         queue<pair<int, int>> q;
//         q.push({start, 0});
//         dist[start] = 0;
//         seta.pb(start);

//         while (!q.empty()) {
//             auto [u, set_u] = q.front(); q.pop();
//             for (int v : adj[u]) {
//                 if (dist[v] == -1) {
//                     dist[v] = dist[u] + 1;
//                     par[v] = u;
//                     if (set_u == 0) {
//                         setb.pb(v);
//                         q.push({v, 1});
//                     } else {
//                         seta.pb(v);
//                         q.push({v, 0});
//                     }
//                 } else if (par[u] != v) {
//                     int cycle_len = dist[u] + dist[v] + 1;
//                     if (cycle_len % 2 == 1) return false;
//                 }
//             }
//         }
//     }

//     return true;
// }

// void solve() {
//     cin >> n >> m;
//     adj.assign(n + 1, {});
//     used.clear();

//     for (int i = 0; i < m; i++) {
//         int a, b; cin >> a >> b;
//         adj[a].pb(b);
//         adj[b].pb(a);
//         used.insert(a);
//         used.insert(b);
//     }

//     if (detectoddlengthcycle()) {
//         cout << seta.size() << endl;
//         for (int x : seta) cout << x << " ";
//         cout << endl;
//         cout << setb.size() << endl;
//         for (int x : setb) cout << x << " ";
//         cout << endl;
//     } else {
//         cout << -1 << endl;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     solve();
//     return 0;
// }

// it was a queation of cheking biparth graph i should used the build team logic here

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> team;
set<int> vertices;
bool bfs(int i)
{

    queue<int> q;
    q.push(i);
    visited[i] = true;
    team[i] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto n : adj[node])
        {
            if (!visited[n])
            {
                team[n] = 3 - team[node];
                visited[n] = true;
                q.push(n);
            }
            else if (team[node] == team[n])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);
    team.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vertices.insert(a);
        vertices.insert(b);
    }
    // now do bfs;

    for (auto i : vertices)
    {
        if (!visited[i])
        {
            if (!bfs(i))
            {
                cout << "-1\n";
                return 0;
            }
        }
    }

  vector<int>seta;vector<int>setb;
  for(auto & i:vertices)
  {
     if(team[i]==1)
    {
        seta.push_back(i);
    }
    else{
        setb.push_back(i);
    }
 }

 cout<<seta.size()<<endl;
 for(auto s:seta) cout<<s<<" ";
 cout<<endl;
 cout<<setb.size()<<endl;
 for(auto s:setb) cout<<s<<" ";

    return 0;
}
