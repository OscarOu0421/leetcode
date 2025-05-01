// Time Complexity: O(m * n), where m = text1.size(), n = text2.size()
// Space Complexity: O(m * n) for the DP table

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Create a DP table of size m x n, initialized to 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Fill the DP table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]) {
                    // Characters match: add 1 to the diagonal value (if in bounds)
                    dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
                } else {
                    // Characters don't match: take max from left or top (if in bounds)
                    if (i > 0)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    if (j > 0)
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        // The result is in the bottom-right cell of the DP table
        return dp[m - 1][n - 1];
    }
};
