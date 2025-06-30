#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int solve(stack<int> visit, int n) {
    stack<int> days;
    
    // Fill the days stack with day numbers 1 to n
    for (int i = 1; i <= n; i++) {
        days.push(i);
    }
    
    int k = n / 2; 
    int count = 0; 
    int ans = 0; 

    while (!visit.empty()) {
        int a = visit.top();
        visit.pop();
        
        // If we can skip the day (count < k) and the visit day is '1'
        if (count < k && a == 1) {
            days.pop(); // Skip the day
            count++;
        } else {
            // If we can't skip or the visit day is not '1', take the item
            ans += days.top(); // Add the value of the top day to the answer
            days.pop(); // Remove that day from the stack
        }
    }
    
    return ans;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after reading t
    while (t--) {
        stack<int> visit;
        int n;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        
        string input;
        getline(cin, input); // Read the entire line of input
        
        stringstream ss(input);
        int data;
        while (ss >> data) {
            visit.push(data);
        }

        int ans = solve(visit, n);
        cout << ans << endl;
    }

    return 0;
}
