/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost,
 you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> // for min function
using namespace std;

int solve(const vector<int>& cost, int n) {
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }
    // Calculate the minimum  cost to reach step `n`
    return cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
}

int main() {
    vector<int> cost;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int data;

    while (ss >> data) {
        cost.push_back(data);
    }

    int n = cost.size();

 
    int ans = min(solve(cost, n - 1), solve(cost, n - 2));
    cout << ans << endl;

    return 0;
}
