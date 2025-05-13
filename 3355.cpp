// Problem:
// Given an integer array `nums` and a list of queries [l, r], each query allows you to 
// decrement any subset of elements in range [l, r] by 1.
// Return true if, after all queries are applied in order, `nums` can be reduced to all zeros.

// Time Complexity: O(n + q), where n = size of nums, q = number of queries
// Space Complexity: O(n), for the difference array

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();                    // Size of the input array
        vector<int> diff(n + 1, 0);             // Difference array for range increment tracking

        // Apply all queries using range increment technique (difference array)
        for (auto query : queries) {
            int l = query[0];
            int r = query[1];
            diff[l] += 1;                       // Begin increment at l
            diff[r + 1] -= 1;                   // Cancel increment after r
        }

        // Accumulate the prefix sums to get how many times each index was decremented
        for (int i = 0; i < n; i++) {
            if (i > 0)
                diff[i] += diff[i - 1];         // Reconstruct the number of allowed decrements at index i
            
            // Check if after applying allowed decrements, nums[i] becomes <= 0
            if (nums[i] - diff[i] > 0)
                return false;                   // Not enough decrements allowed to bring this element to zero
        }

        return true;                            // All elements can be reduced to zero
    }
};
