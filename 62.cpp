// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
// DP Formula: dp[i][j] = dp[i-1][j] + dp[i][j-1]

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Initialize DP table with 1s since there's only one way to reach cells in the first row/column
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Fill DP table using the recurrence relation
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // Return the number of unique paths to the bottom-right corner
        return dp[m-1][n-1];
    }
};
