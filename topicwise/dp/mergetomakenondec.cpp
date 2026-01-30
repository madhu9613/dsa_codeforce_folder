#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {       
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    // dp[i] = max segments using first i elements
    vector<int> dp(n + 1, 0);
    // last_s[i] = the sum of the last segment in that optimal partition
    vector<ll> last_s(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        // Look for the best previous split point j
        // We go backwards from i-1 to find the largest j (smallest last_s[i])
        for (int j = i - 1; j >= 0; j--)
        {
            ll current_segment_sum = pref[i] - pref[j];
            if (current_segment_sum >= last_s[j])
            {
                dp[i] = dp[j] + 1;
                last_s[i] = current_segment_sum;
                break; // Found the best j
            }
        }
    }

    // Min operations = Total elements - Max segments
    cout << n - dp[n] << endl;

    return 0;
}