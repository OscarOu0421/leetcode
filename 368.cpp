// Time Complexity: O(n^2)
// - Sorting: O(n log n)
// - Nested loop for DP: O(n^2)
// Space Complexity: O(n)
// - dp: O(n)
// - parent: O(n)
// - result: up to O(n) for the final subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();  // Size of the input array
        if (n == 0) return {};  // Return empty vector for empty input

        sort(nums.begin(), nums.end());  // Sort the input array to ensure increasing order

        vector<int> dp(n, 1);  // dp[i] stores length of the largest divisible subset ending at index i
        vector<int> parent(n, -1);  // parent[i] stores the previous index in the subset chain

        int maxIdx = 0;  // Index of the largest subset found so far

        // Build the dp and parent arrays
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Only check nums[i] % nums[j] == 0 because:
                // We want a subset where every pair (a, b) satisfies a % b == 0 or b % a == 0.
                // Since the array is sorted, and nums[i] >= nums[j], we only need to check nums[i] % nums[j] == 0.
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;  // Update max length for i
                    parent[i] = j;  // Set j as the predecessor of i
                }
            }
            if (dp[i] > dp[maxIdx]) {  // Track the index with the longest subset
                maxIdx = i;
            }
        }

        // Reconstruct the largest subset by backtracking from maxIdx
        vector<int> result;
        for (int i = maxIdx; i >= 0; i = parent[i]) {
            result.push_back(nums[i]);  // Add current number to the result
            if (parent[i] == -1) break;  // Stop if no parent
        }

        reverse(result.begin(), result.end());  // Subset was built in reverse order
        return result;
    }
};

