// Time Complexity: O(n log n)
//   - O(n) to compute arrival times
//   - O(n log n) to sort cars by position
//   - O(n) to process fleets using stack
//
// Space Complexity: O(n)
//   - For the cars vector and stack

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();            // Number of cars
        int ret = 0;                        // Fleet counter (unused here but kept from original code)
        vector<pair<int, double>> cars(n); // Store each car as {position, time to reach target}
        double cur_hours = INT_MIN;        // Unused in final logic
        stack<double> sk;                  // Stack to track distinct fleet arrival times

        // Calculate time for each car to reach the target
        for (int i = 0; i < n; i++) {
            double hours = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], hours};
        }

        // Sort cars in descending order of position (closest to target first)
        sort(cars.rbegin(), cars.rend());

        // Traverse sorted cars
        for (auto [pos, hours] : cars) {
            // If stack is empty or current car takes longer, it forms a new fleet
            if (sk.empty() || hours > sk.top()) {
                sk.push(hours); // Start a new fleet
            }
            // Else it joins the fleet on top of the stack (do nothing)
        }

        // Number of fleets is equal to stack size
        return sk.size();
    }
};
