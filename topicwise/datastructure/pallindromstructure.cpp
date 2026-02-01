#include <bits/stdc++.h>
using namespace std;

struct PalStructure
{
    int middle; // -1 if no middle
    array<int, 26> half;

    bool operator<(const PalStructure &other) const
    {
        if (middle != other.middle)
            return middle < other.middle;
        return half < other.half;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 26>> freq(n);
    vector<int> len(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        len[i] = s.size();
        for (char c : s)
            freq[i][c - 'a']++;
    }

    set<PalStructure> structures;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int odd = 0, mid = -1;
            array<int, 26> combined{};

            for (int c = 0; c < 26; c++)
            {
                combined[c] = freq[i][c] + freq[j][c];
                if (combined[c] & 1)
                {
                    odd++;
                    mid = c;
                }
            }

            if (odd > 1)
                continue;

            PalStructure ps;
            ps.middle = (odd == 1 ? mid : -1);
            for (int c = 0; c < 26; c++)
                ps.half[c] = combined[c] / 2;

            structures.insert(ps);
        }
    }

    cout << structures.size() << "\n";
    return 0;
}
