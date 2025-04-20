/*
 * Problem: Palindromic Substrings
 * Link: LeetCode 647 - https://leetcode.com/problems/palindromic-substrings/
 *
 * Given a string `s`, count how many substrings are palindromes.
 * A substring is a contiguous block of characters, and palindromes read the same forward and backward.
 *
 * Approach:
 * - Use dynamic programming to store whether s[i..j] is a palindrome.
 * - dp[i][j] = true if:
 *     - i == j (single character), or
 *     - s[i] == s[j] and either:
 *         - j - i == 1 (two characters), or
 *         - dp[i+1][j-1] == true (inner substring is a palindrome)
 * - Iterate from bottom-up so that dp[i+1][j-1] is filled before dp[i][j]
 *
 * Time Complexity: O(n^2)
 *   - Two nested loops over the string.
 *
 * Space Complexity: O(n^2)
 *   - 2D DP table to store results for all substrings.
 */

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ret = 0;

        // dp[i][j] is true if the substring s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Traverse i backward so that dp[i+1][j-1] is already known when needed
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    // Single character is always a palindrome
                    dp[i][j] = true;
                }
                else if (s[i] == s[j] && (j - i == 1 || dp[i+1][j-1])) {
                    // Two characters are the same OR the inner substring is a palindrome
                    dp[i][j] = true;
                }

                // Count the palindrome if dp[i][j] is true
                ret += dp[i][j] ? 1 : 0;
            }
        }

        return ret; // Total palindromic substrings
    }
};
