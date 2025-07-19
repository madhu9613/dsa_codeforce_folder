#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValidSubarray(const vector<int>& arr, int minElement, int medCandidate) {
    int n = arr.size();
    int prefixScore = 0, minPrefix = 0;
    int minPrefixWhenMinSeen = INT_MAX;
    bool insideSegment = false, hasMinElement = false;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < minElement) {
            insideSegment = false; 
        } else {
            if (!insideSegment) {
                insideSegment = true;
                prefixScore = 0;
                minPrefix = 0;
                minPrefixWhenMinSeen = INT_MAX;
                hasMinElement = false;
            }

            if (arr[i] == minElement) {
                hasMinElement = true;
                minPrefixWhenMinSeen = min(minPrefixWhenMinSeen, minPrefix);
            }

            prefixScore += (arr[i] >= medCandidate) ? 1 : -1;
            minPrefix = min(minPrefix, prefixScore);

            if (hasMinElement && prefixScore - minPrefixWhenMinSeen >= 0)
                return true;
        }
    }

    return false;
}

int maxMedianMinusMin(const vector<int>& arr) {
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());

    vector<int> frequency(maxi + 1, 0);
    for (int value : arr) frequency[value]++;

    int maxDifference = 0;

    for (int mini = 1; mini <= maxi; ++mini) {
        if (frequency[mini] == 0) continue;

        int left = mini + 1;
        int right = maxi;
        int bestMedian = mini;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (isValidSubarray(arr, mini, mid)) {
                bestMedian = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        maxDifference = max(maxDifference, bestMedian - mini);
    }

    return maxDifference;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << maxMedianMinusMin(arr) << '\n';
    }

    return 0;
}
