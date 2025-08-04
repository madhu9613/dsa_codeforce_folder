#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

//i need to check can i remove an one  bad level ;
//if i found discontinuty in trend in i and i+1 level i will try to remove (i) and (i+1);
bool checkValid(const vector<int>& row) {
    if (row.size() < 2) return false;

    auto isGood = [](const vector<int>& r) -> bool {
        if (r.size() < 2) return false;
        bool increasing = r[1] > r[0];
        bool decreasing = r[1] < r[0];
        if (!increasing && !decreasing) return false;

        for (size_t i = 1; i < r.size(); ++i) {
            int diff = abs(r[i] - r[i - 1]);
            if (diff < 1 || diff > 3) return false;
            if (increasing && r[i] <= r[i - 1]) return false;
            if (decreasing && r[i] >= r[i - 1]) return false;
        }
        return true;
    };

    if (isGood(row)) return true;

    for (size_t i = 1; i < row.size(); ++i) {
        int diff = abs(row[i] - row[i - 1]);
        if (diff < 1 || diff > 3 || row[i] == row[i - 1]) {
            vector<int> temp1 = row;
            temp1.erase(temp1.begin() + i - 1);
            if (isGood(temp1)) return true;

            vector<int> temp2 = row;
            temp2.erase(temp2.begin() + i);
            if (isGood(temp2)) return true;

            return false;
        }

        if ((row[1] > row[0] && row[i] <= row[i - 1]) ||
            (row[1] < row[0] && row[i] >= row[i - 1])) {
            vector<int> temp1 = row;
            temp1.erase(temp1.begin() + i - 1);
            if (isGood(temp1)) return true;

            vector<int> temp2 = row;
            temp2.erase(temp2.begin() + i);
            if (isGood(temp2)) return true;

            return false;
        }
    }

    return true;
}


void solve() {
    int safecount=0;
    vector<vector<int>> data;
    string line;
     while (getline(cin, line)) {
        stringstream ss(line);
        int num;
        vector<int> row;
        while (ss >> num) {
            row.push_back(num);
        }
        if(checkValid(row))
        {
            safecount++;
        }
        
    }
    cout<<safecount<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}