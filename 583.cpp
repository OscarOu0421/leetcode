// Time Complexity: O(m * n)
//   - where m = word1.length(), n = word2.length()
//   - Nested loops iterate over all pairs of indices from both words
// Space Complexity: O(m * n)
//   - A 2D dp table of size (m+1) x (n+1) is used

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j] will store the minimum number of deletions to make
        // word1[0..i-1] and word2[0..j-1] equal
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        // If word2 is empty, delete all characters from word1
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;

        // If word1 is empty, delete all characters from word2
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no deletion needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Delete one character: either from word1 or word2
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        // Final answer is min deletions to make both strings equal
        return dp[m][n];
    }
};
