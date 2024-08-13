// TC:O(n^2)
// SC:O(n^2)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

        /*
         * DP:
         * dp[i][j] means s3[0 : i+j-2] is formed by an interleaving of s1[0 : i-1] and s2[0 : j-1]
         * 0th position means empty string
         *
         * 1. if both s1 and s2 are empty, and s3 is empty, then it is considered interleaving.
         * 2. if only s1 is empty, then if previous s2 position is interleaving and current s2 char is equal to current s3 position,
         * then it is considered interleaving.
         * 3. similar idea when s2 is empty
         * 4. when both s1 and s2 is not empty
         * 4.1. if we arrive i, j from i-1, j, then if i-1,j is already interleaving and i and current s3 position equal, it s interleaving.
         * 4.2. if we arrive i,j from i, j-1, then if i, j-1 is already interleaving and j and current s3 position equal. it is interleaving.
         */

        if (n1 + n2 != n3)
            return false;

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[j-1];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i-1];
                else
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[n1][n2];
    }
};
