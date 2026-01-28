// Time Complexity: O(n) — We traverse the input array twice (once for each scenario).
// Space Complexity: O(1) — We only use a fixed number of integer variables, regardless of the input size.

class Solution {
public:
    // Helper function to solve the linear version of the problem for a specific range
    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0; // Stores the max profit from two houses ago
        int prev1 = 0; // Stores the max profit from one house ago
        
        // Iterate through the houses in the current range
        for (int i = start; i <= end; i++) {
            // Temporary variable to hold the 'prev1' value before we update it
            int temp = prev1; 
            
            // Recurrence: Either rob this house (nums[i] + prev2) or skip it (prev1)
            prev1 = max(nums[i] + prev2, prev1);
            
            // Move our sliding window: current prev1 becomes the next iteration's prev2
            prev2 = temp;
        }
        // Return the final maximum profit for this range
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the total number of houses
        
        // Edge case: If there's only one house, just rob it
        if (n == 1) return nums[0];

        // Because the houses are in a circle, we can't rob both the first and the last house.
        // We calculate the max for two scenarios and take the best one:
        
        // Scenario 1: Consider houses from index 0 to n-2 (exclude the last house)
        int choice1 = robRange(nums, 0, n - 2);
        
        // Scenario 2: Consider houses from index 1 to n-1 (exclude the first house)
        int choice2 = robRange(nums, 1, n - 1);
        
        // Return the maximum of the two scenarios
        return max(choice1, choice2);
    }
};
