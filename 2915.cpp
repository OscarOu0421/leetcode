// Time Complexity: O(n * target), where n = size of nums
// Space Complexity: O(target), for the DP array

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);  // dp[i] = length of the longest subsequence that sums to i

        dp[0] = 1;  // Base case: 1 way to get sum 0 using 0 elements (length = 0 + 1 for offset)
        
        for (auto num : nums) {  // Iterate over each number in the input
            for (int i = target; i >= num; i--) {  // Traverse backwards to prevent reuse of the same number
                if (dp[i - num])                   // If there's a way to make sum i - num
                    dp[i] = max(dp[i - num] + 1, dp[i]);  // Try extending that subsequence with current num
            }
        }

        // If dp[target] == 0, no valid subsequence was found
        return dp[target] - 1;  // Subtract 1 to get actual length (we added +1 earlier to avoid 0-conflict)
    }
};
