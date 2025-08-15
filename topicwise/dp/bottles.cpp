#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int total_soda = accumulate(a.begin(), a.end(), 0);

    vector<pair<int,int>> bottles;
    for(int i=0;i<n;i++) bottles.push_back({b[i], i});
    sort(bottles.rbegin(), bottles.rend()); 

   
    int sum_vol = 0, k = 0;
    for(int i=0;i<n;i++){
        sum_vol += bottles[i].first;
        k++;
        if(sum_vol >= total_soda) break;
    }

   
    vector<int> target(k);
    for(int i=0;i<k;i++) target[i] = b[bottles[i].second];

  
    vector<int> soda = a;

    vector<int> sources;
    for(int i=0;i<n;i++){
        bool is_target = false;
        for(int j=0;j<k;j++){
            if(bottles[j].second == i){ is_target = true; break;}
        }
        if(!is_target) sources.push_back(i);
    }

    long long t = 0;
    for(int src: sources){
        int remaining = soda[src];
        for(int j=0;j<k && remaining>0;j++){
            int can_pour = min(remaining, target[j] - soda[bottles[j].second]);
            soda[bottles[j].second] += can_pour;
            remaining -= can_pour;
            t += can_pour;
        }
    }

    cout << k << " " << t << "\n";
}
