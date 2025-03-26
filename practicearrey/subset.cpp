#include<iostream>
#include<vector>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

void solve(set<int>::iterator it, set<int>::iterator end, vector<int> output, vector<vector<int>>& ans) {
    if (it == end) {
        ans.push_back(output);  
        return;
    }

    solve(next(it), end, output, ans);

    output.push_back(*it);
    solve(next(it), end, output, ans);
}

vector<vector<int>> subset(set<int>& s) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(s.begin(), s.end(), output, ans);
    return ans;
}

int main() {
    set<int> s;
    string input;

    getline(cin, input);
    stringstream ss(input);
    int data;

    while (ss >> data) {
        s.insert(data);
    }

    vector<vector<int>> result = subset(s);

    sort(result.begin(), result.end());

    // Print the subsets in sorted order
    cout << "Subsets in sorted order:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
