#include <bits/stdc++.h>
using namespace std;

string n;
int L, half;
string ans;

bool solve(int pos, int need4, int need7, bool tight, string &res)
{
    if (pos == L)
        return true;

    int rem = L - pos - 1;

    for (int d : {4, 7})
    {
        if (d == 4 && need4 == 0)
            continue;
        if (d == 7 && need7 == 0)
            continue;

        int nn4 = need4 - (d == 4 ? 1 : 0);
        int nn7 = need7 - (d == 7 ? 1 : 0);
        if (nn4 + nn7 != rem)
            continue;

        int cur = n[pos] - '0';
        if (tight && d < cur)
            continue;

        bool newTight = tight && (d == cur);
        res.push_back('0' + d);

        if (!newTight)
        {
            res += string(nn4, '4');
            res += string(nn7, '7');
            return true;
        }

        if (solve(pos + 1, nn4, nn7, newTight, res))
            return true;

        res.pop_back(); 
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    L = n.size();

    if (L % 2)
    {
        int newL = L + 1;
        cout << string(newL / 2, '4') + string(newL / 2, '7') << endl;
        return 0;
    }

    half = L / 2;
    string res = "";

    if (solve(0, half, half, true, res))
    {
        cout << res << endl;
    }
    else
    {
        int newL = L + 2;
        cout << string(newL / 2, '4') + string(newL / 2, '7') << endl;
    }

    return 0;
}