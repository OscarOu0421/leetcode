// TC: O(n)
// SC: O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        
        for (int i = 0; i <= n; i++) {
            if (i == 1 || i == 0) {
                dp[i] = 1;
                continue;
            }
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
