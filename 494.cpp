/*
Formula:
    The original problem is to assign '+' or '-' to each number to reach the target sum.
    This is equivalent to splitting nums into two subsets:
        P (positive sign) and N (negative sign), such that:
            sum(P) - sum(N) = target
        And since sum(P) + sum(N) = total_sum,
        We derive:
            2 * sum(P) = target + total_sum
            sum(P) = (target + total_sum) / 2

    So the problem reduces to finding the number of subsets of nums that sum to:
        target_sum = (target + total_sum) / 2

Constraints:
    - Each number is used exactly once (0/1 Knapsack).
    - If (sum + target) is odd or target > sum, there's no valid subset.

Time Complexity: O(n * target_sum)
Space Complexity: O(target_sum)
Where:
    - n = nums.size()
    - target_sum = (sum + target) / 2
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();                // Size of the input array
        int sum = 0;                        // Total sum of all elements
        int target_sum = 0;                 // The subset sum we want to find
        vector<int> dp;                     // DP array for subset sum

        // Compute the total sum of the array
        for (auto num : nums)
            sum += num;

        // Check if a valid target_sum is possible
        if ((sum + target) % 2 || abs(target) > sum)
            return 0;

        // Calculate the subset sum we need to find
        target_sum = (sum + target) / 2;

        // Initialize the DP array
        dp.resize(target_sum + 1, 0);
        dp[0] = 1; // Base case: one way to reach sum 0 (use no elements)

        // 0/1 Knapsack: update DP array backwards to avoid reusing elements
        for (auto num : nums) {
            for (int i = target_sum; i >= num; i--)
                dp[i] += dp[i - num];
        }

        // Return the number of subsets with sum == target_sum
        return dp[target_sum];
    }
};

