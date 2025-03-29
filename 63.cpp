// Time Complexity: O(m * n) 
// Space Complexity: O(m * n) 
// DP Formula: dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i-1][j] + dp[i][j-1]

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // DP array initialized with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Traverse the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // If there's an obstacle, no paths can go through this cell
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }

                // Starting cell initialization
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                // Collect paths from top and left cells (if within bounds)
                int top = j - 1 >= 0 ? dp[i][j-1] : 0;
                int left = i - 1 >= 0 ? dp[i-1][j] : 0;

                dp[i][j] = top + left;
            }
        }

        // Return the number of unique paths to the bottom-right corner
        return dp[m-1][n-1];
    }
};
