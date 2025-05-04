// Time Complexity: O(N * A), where N = number of coin types, A = target amount
// Space Complexity: O(A), using a 1D dp array to store minimum coins for each amount

// This is an Unbounded Knapsack problem:
// - Each coin can be used unlimited times.
// - Goal: Minimize the number of coins to reach the target amount.
// - Key implementation detail: Inner loop goes FORWARD to allow multiple uses of the same coin.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); // dp[i] = min number of coins to get amount i
        dp[0] = 0;  // Base case: 0 coins needed for amount 0

        // Outer loop over coins: ensures each coin can be reused (Unbounded Knapsack)
        for (int coin : coins) {
            // Inner loop moves forward: allows using the same coin multiple times
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

