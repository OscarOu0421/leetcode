// Time Complexity: O(m * n)
// Space Complexity: O(n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of columns
        vector<int> dp(n, 0);   // 1D DP array for space optimization

        // Initialize the first row
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j]; // fill in first row
        }

        // Compute values row by row
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0]; // update first column
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j]; // update each cell using previous values
            }
        }

        return dp[n - 1]; // return the bottom-right corner value
    }
};
