// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int len = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j || (j - i == 1 && s[i] == s[j]))
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if (dp[i][j] && j - i + 1 > len) {
                    len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, len);
    }
};
