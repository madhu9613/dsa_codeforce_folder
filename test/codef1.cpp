#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> elements;
        map<int, int> freq;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            elements.insert(x);
            freq[x]++;
        }

        int score = 0;
        for (auto &pair : freq) {
            score += pair.second / 2; 
        }

        cout << score << endl;
    }
    return 0;
}
