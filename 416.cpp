// Time Complexity: O(n * target) — where n is the number of elements, and target = total_sum / 2
// Space Complexity: O(target) — using 1D DP array to optimize space
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        // Step 1: Calculate total sum of all elements
        for (int num : nums) total += num;

        // Step 2: If total is odd, can't split into equal subsets
        if (total % 2 != 0) return false;

        int target = total / 2;

        // Step 3: dp[i] = true means a subset with sum i is possible
        vector<bool> dp(target + 1, false);
        dp[0] = true; // We can always form sum 0 with no elements

        // Step 4: Process each number in the array
        for (int num : nums) {
            // Loop backward to prevent using the same number multiple times
            for (int i = target; i >= num; --i) {
                // If we can make sum (i - num), then we can make sum i by adding num
                dp[i] = dp[i] || dp[i - num];
            }
        }

        // Step 5: If dp[target] is true, then we can partition into two equal subsets
        return dp[target];
    }
};
