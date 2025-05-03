// Time Complexity: O(n)
// Space Complexity: O(n)
// n = number of days (length of prices array)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            dp[i][0] - Maximum profit on day i when we do NOT hold a stock
            dp[i][1] - Maximum profit on day i when we DO hold a stock
        */
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0)); // DP table: n days x 2 states

        dp[0][0] = 0;               // On day 0, not holding stock = 0 profit
        dp[0][1] = -prices[0];      // On day 0, buying stock = -price[0] cost

        for (int i = 1; i < n; i++) {
            // Max profit today if we don't hold stock:
            // Either we didn't hold yesterday, or we sell today
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);

            // Max profit today if we hold stock:
            // Either we held yesterday, or we buy today (after cooldown if i >= 2)
            if (i >= 2)
                dp[i][1] = max(dp[i-2][0] - prices[i], dp[i-1][1]);
            else
                dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }

        // Final answer: max profit on last day with no stock in hand
        return dp[n-1][0];
    }
};
