// Recurrence Relation:
// If word1[i-1] == word2[j-1]:
//     dp[i][j] = dp[i-1][j-1]
// Else:
//     dp[i][j] = 1 + min(
//         dp[i-1][j-1], // Replace operation
//         dp[i-1][j],   // Delete operation
//         dp[i][j-1]    // Insert operation
//     )
//
// Time Complexity: O(m * n) - where m = word1.length(), n = word2.length()
// Space Complexity: O(m * n) - for the 2D dp table
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(); // Length of word1
        int n = word2.size(); // Length of word2
        
        // Create a 2D DP table initialized with 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // If either word is empty, minimum operations = length of the other word
        if (m == 0 || n == 0) {
            return max(m, n); // Insert all or delete all characters
        }

        // Initialize the first column: delete all characters from word1
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        // Initialize the first row: insert all characters into word1
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1]; // Characters match, no operation needed
                else {
                    // Characters differ: take the minimum of replace, delete, or insert
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[m][n]; // Final answer: min operations to convert word1 to word2
    }
};
