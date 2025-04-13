/*
 * Problem: 322. Coin Change
 *
 * Approach:
 * - Use Dynamic Programming to compute the minimum number of coins needed to make up each amount.
 * - `dp[i]` stores the minimum number of coins to get amount `i`.
 * - Initialize dp[0] = 0, and the rest with a large value (infinity).
 * - For each amount from 1 to `amount`, try using each coin to minimize `dp[i]`.
 *
 * Time Complexity: O(amount * n), where n = number of coin denominations
 * Space Complexity: O(amount)
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // use amount+1 as "infinity"
        dp[0] = 0; // 0 coins to make amount 0

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
