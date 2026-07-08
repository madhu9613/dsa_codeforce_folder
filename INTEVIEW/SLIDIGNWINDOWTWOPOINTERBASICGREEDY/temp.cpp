#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>

int main()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Prefix sum
    vll pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
    }

    unordered_map<int, int> freqK, freqK1;

    int leftK = 0, leftK1 = 0;
    int added = 0; // like your dq logic extension

    deque<int> dq;

    ll maxsum = LLONG_MIN;

    for (int r = 0; r < n; r++)
    {

        // Maintain at most K distinct
        freqK[a[r]]++;
        while (freqK.size() > k)
        {
            if (--freqK[a[leftK]] == 0)
                freqK.erase(a[leftK]);
            leftK++;
        }

        // Maintain at most K-1 distinct
        freqK1[a[r]]++;
        while (freqK1.size() > k - 1)
        {
            if (--freqK1[a[leftK1]] == 0)
                freqK1.erase(a[leftK1]);
            leftK1++;
        }

        // Only if exactly K distinct
        if (freqK.size() == k)
        {

            // Add all new valid start indices
            while (added <= leftK1 - 1)
            {
                while (!dq.empty() && pref[dq.back()] >= pref[added])
                    dq.pop_back();

                dq.push_back(added);
                added++;
            }

            // Remove invalid starts
            while (!dq.empty() && dq.front() < leftK)
                dq.pop_front();

            // Compute answer
            if (!dq.empty())
            {
                ll cur = pref[r + 1] - pref[dq.front()];
                maxsum = max(maxsum, cur);
            }
        }
    }

    cout << (maxsum == LLONG_MIN ? 0 : maxsum) << endl;
}