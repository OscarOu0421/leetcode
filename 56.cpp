// Time Complexity: O(n log n) - Sorting dominates the overall complexity
// Space Complexity: O(n) - The output vector can store up to n intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret; // Result container for merged intervals

        // Sort intervals based on the starting points
        sort(intervals.begin(), intervals.end());

        // Iterate through sorted intervals
        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // If result is empty, or no overlap with the last added interval
            if (ret.empty() || start > ret.back()[1]) {
                ret.push_back({start, end}); // Add new interval
            } else {
                // Merge overlapping intervals by updating the endpoint
                ret.back()[1] = max(ret.back()[1], end);
            }
        }
        return ret; // Return merged intervals
    }
};
