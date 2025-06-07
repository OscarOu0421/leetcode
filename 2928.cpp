// Time Complexity: O(n * limit)
// - There are O(n * 3) unique (n, num) states in the dp table (since num ∈ [1,3]).
// - Each state makes up to 'limit + 1' recursive calls (bounded by the loop).
// - Hence total work is O(n * limit).
//
// Space Complexity: O(n * 4) = O(n)
// - For the dp table storing results for each (n, num) state.

class Solution {
public:
    // Recursive helper to compute number of ways to distribute `n` candies among `num` children
    // with no one receiving more than `limit` candies.
    void helper(int n, int limit, int num, vector<vector<long long>> &dp) {
        // Memoization check: if already computed, return
        if (dp[n][num] != 0)
            return;

        // Base case: only one child left
        if (num == 1) {
            // Only valid if n candies ≤ limit
            dp[n][num] = (n <= limit ? 1 : 0);
            return;
        }

        long long count = 0;

        // Try giving i candies (0 to min(limit, n)) to current child
        for (int i = 0; i <= min(limit, n); i++) {
            helper(n - i, limit, num - 1, dp);        // Recursively compute for remaining candies and children
            count += dp[n - i][num - 1];              // Accumulate results
        }

        dp[n][num] = count; // Store result in memo table
    }

    // Main function to start the recursion with 3 children
    long long distributeCandies(int n, int limit) {
        // dp[i][j]: ways to distribute i candies among j children
        vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
        helper(n, limit, 3, dp);
        return dp[n][3];
    }
};

