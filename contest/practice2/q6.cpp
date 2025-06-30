#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int min_time_to_turn_off_lights(int n, int m, vector<string>& building) {
    int total_time = 0;
    
    // Start from the ground floor, positioned at the left stairway
    int prev_left_time = 0, prev_right_time = 0;

    for (int i = 0; i < n; i++) {
        string floor = building[i];
        
        // Find rooms with lights on
        vector<int> rooms_with_lights;
        for (int j = 1; j <= m; j++) {
            if (floor[j] == '1') {
                rooms_with_lights.push_back(j);
            }
        }
        
        // If there are no lights on, no time needed for this floor
        if (rooms_with_lights.empty()) {
            continue;
        }

        // Time to visit all rooms starting from the left stair
        int left_time = (rooms_with_lights.back() - rooms_with_lights.front()) + 2;
        // Time to visit all rooms starting from the right stair
        int right_time = (rooms_with_lights.back() - rooms_with_lights.front()) + 2;

        // If there are lights on, calculate time for both strategies
        int min_floor_time = min(left_time, right_time);

        // Update total time based on the current floor time
        total_time += min_floor_time;
    }
    return total_time;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> building(n);
    for (int i = 0; i < n; i++) {
        cin >> building[i];
    }

    int result = min_time_to_turn_off_lights(n, m, building);
    cout << result << endl;

    return 0;
}
