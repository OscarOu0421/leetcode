// Time Complexity: O(n * amount), where n is the number of coins
// Space Complexity: O(amount), for the dp array

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i] will store the number of combinations to make amount i
        vector<unsigned long long> dp(amount+1, 0);

        // There's one way to make amount 0: choose no coins
        dp[0] = 1;

        // For each coin, update the dp array
        for (auto coin : coins) {
            // For all amounts from coin to amount, update the number of ways
            for (int i = coin; i <= amount; i++) {
                // Add the number of ways to make (i - coin) to dp[i]
                dp[i] += dp[i - coin];
            }
        }

        // Return the number of ways to make the full amount
        return dp[amount];
    }
};
