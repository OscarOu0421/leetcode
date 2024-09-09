// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ret = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i] == s[j] && (j - i == 1 || dp[i+1][j-1]))
                    dp[i][j] = 1;
                ret += dp[i][j];
            }
        }
        return ret;
    }
};
