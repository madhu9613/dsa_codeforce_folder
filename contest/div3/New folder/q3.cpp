#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define endl '\n'

using ll = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, pos;
        cin >> n >> pos;

        vector<int> heights(n);
        for (int &height : heights) cin >> height;

        int current = heights[pos - 1];
        int maxHeight = *max_element(all(heights));

        if (current == maxHeight) {
            cout << "YES\n";
            continue;
        }

        vector<int> uni = heights;
        sort(all(uni));
        uni.erase(unique(all(uni)), uni.end());

        int startIndex = lower_bound(all(uni), current) - uni.begin();
        bool possible = true;
        int N=uni.size();
        for (int i = startIndex; i<N-1; ++i) {
            if (uni[i + 1] - uni[i] > current) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
