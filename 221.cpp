/*
 * Time Complexity: O(m * n)
 *   - Each cell in the matrix is visited once.
 *
 * Space Complexity: O(m * n)
 *   - A 2D DP table of the same size as the matrix is used.
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ret = 0;  // Stores the maximum square area found
        vector<vector<int>> dp(m, vector<int>(n, 0));  // DP table to store side length of largest square ending at (i,j)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Only process cells with '1'
                if (matrix[i][j] == '1') {
                    if (i > 0 && j > 0) {
                        // Take minimum of top, left, and top-left neighbors
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    } else {
                        dp[i][j] = 1;  // Cells in first row or first column can only form 1x1 square
                    }
                    // Update maximum area found so far
                    ret = max(ret, dp[i][j] * dp[i][j]);
                }
            }
        }

        return ret;  // Return the area of the largest square found
    }
};
