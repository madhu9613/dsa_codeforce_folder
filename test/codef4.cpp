#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store engineer data
struct Engineer {
    int id;       // Index of the engineer
    long long a;  // Bonus amount
    long long b;  // Work unit cost
};

// Comparator for sorting engineers by benefit-to-cost ratio
bool compare(const Engineer& e1, const Engineer& e2) {
    return e1.a * e2.b > e2.a * e1.b; // Compare ratios a1/b1 and a2/b2
}

int main() {
    int n;       // Number of engineers
    long long k; // Total work required
    cin >> n >> k;

    vector<Engineer> engineers(n);
    vector<long long> work(n, 0);

    // Input bonus and cost for each engineer
    for (int i = 0; i < n; ++i) {
        cin >> engineers[i].a;
        engineers[i].id = i; // Save original index
    }
    for (int i = 0; i < n; ++i) {
        cin >> engineers[i].b;
    }

    // Sort engineers by benefit-to-cost ratio
    sort(engineers.begin(), engineers.end(), compare);

    long long remainingWork = k;

    // Distribute work optimally
    for (const auto& e : engineers) {
        if (remainingWork <= 0) break;
        long long maxWork = e.a / e.b; // Maximum work this engineer is willing to do
        long long assignedWork = min(maxWork, remainingWork);
        work[e.id] = assignedWork;
        remainingWork -= assignedWork;
    }

    // If the required work is not completed, all work is zero
    if (remainingWork > 0) {
        fill(work.begin(), work.end(), 0);
    }

    // Output the work distribution
    for (long long w : work) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
