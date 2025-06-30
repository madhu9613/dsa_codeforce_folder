
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

vector<int> tree[MAXN];
int size_sub[MAXN];
int centroid[MAXN];

void dfs(int u, int parent) {
    size_sub[u] = 1;
    centroid[u] = u;

    for (int v : tree[u]) {
        if (v == parent) continue;

        dfs(v, u);
        size_sub[u] += size_sub[v];
    }

    // Find centroid of u's subtree
    for (int v : tree[u]) {
        if (v == parent) continue;

        // Candidate for centroid
        if (size_sub[v] > size_sub[u] / 2) {
            int candidate = centroid[v];

            // Move up toward root while violating centroid condition
            while (size_sub[u] - size_sub[candidate] > size_sub[u] / 2) {
                // Move one step up
                for (int par : tree[candidate]) {
                    if (size_sub[par] > size_sub[candidate] && size_sub[par] < size_sub[u]) {
                        candidate = par;
                        break;
                    }
                }
            }

            centroid[u] = candidate;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n==1)
    {
        cout<<1<<" "<<endl;
        return 0;
    }

    int a1,b1;cin>>a1>>b1;
    tree[a1].push_back(b1);
    tree[b1].push_back(a1);
    for (int i = 0; i <n-2; ++i) {
        int a,b;
        cin >>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(a1, 0);

 
  
    cout << centroid[a1] << '\n';
  

    return 0;
}
