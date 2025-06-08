#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> lastOcc(n+1, -1);
        for (int i = n-1; i >= 0; i--) {
            int x = a[i];
            if (lastOcc[x] == -1) {
                lastOcc[x] = i;
            }
        }

        vector<char> needed(n+1, 0), seen(n+1, 0);
        int neededMissing = 0;   
        int currentBad = 0;     

        vector<int> currVals;    
        int segments = 0;

        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (!seen[x]) {
                seen[x] = 1;
                currVals.push_back(x);
                if (lastOcc[x] <= i) {
                    currentBad++;
                }
                if (needed[x]) {
                    neededMissing--;
                }
            }
            else {
                if (lastOcc[x] == i) {
                    currentBad++;
                }
            }

            if (currentBad == 0 && neededMissing == 0) {
                segments++;
                neededMissing = 0;
                for (int v : currVals) {
                    needed[v] = 1;
                    neededMissing++;
                    seen[v] = 0;  
                }
                currVals.clear();
                currentBad = 0;
            }
        }
        if (!currVals.empty()) {
            segments++;
        }

        cout << segments << "\n";
    }
    return 0;
}
