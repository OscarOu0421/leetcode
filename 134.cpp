// Time Complexity: O(n)
//   - Each station is visited exactly once.
// Space Complexity: O(1)
//   - Uses only a few integer variables; no extra data structures.
//
// This greedy solution determines the starting station (if any) from which
// you can complete a circular route given gas and cost at each station.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();     // Total number of stations
        int cur = 0;            // Current gas balance while scanning
        int sum = 0;            // Total gas-cost balance
        int ret = 0;            // Potential starting station index

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];  // Net gas after reaching next station
            sum += diff;                  // Track total balance over the whole circuit
            cur += diff;                  // Track current balance

            if (cur < 0) {
                // If current balance goes negative, can't start from previous ret
                // Try next station as new starting point
                ret = i + 1;
                cur = 0;  // Reset current balance
            }
        }

        // If total sum is negative, trip is impossible
        return sum >= 0 ? ret : -1;
    }
};
