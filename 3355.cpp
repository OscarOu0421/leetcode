// Time Complexity: O(n + q), where n = size of nums, q = number of queries
// Space Complexity: O(n), for the difference array `v`

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int count = 0;
        vector<int> v(n + 1, 0);  // Difference array to track cumulative decrements

        // Apply range updates using the difference array technique
        for (auto q : queries) {
            v[q[0]]--;          // Start of decrement range
            v[q[1] + 1]++;      // End of decrement range (exclusive)
        }

        // Accumulate the difference and apply to nums
        for (int i = 0; i < n; i++) {
            count += v[i];      // Accumulate total decrement at index i
            if (nums[i] + count > 0) // If any element remains > 0, return false
                return false;
        }

        return true; // All elements are ≤ 0 after applying queries
    }
};
