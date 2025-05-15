// Time Complexity: O(n * sqrt(n))
//   - Outer loop runs sqrt(n) times (for each i where i*i <= n)
//   - Inner loop runs up to (n - i*i + 1) times for each i
// Space Complexity: O(n)
//   - A 1D dp array of size n+1 is used

class Solution {
public:
    int numSquares(int n) {
        // dp[i] stores the minimum number of perfect squares that sum up to i
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0; // Base case: 0 can be formed with 0 perfect squares

        // Try all perfect squares less than or equal to n
        for (int i = 1; i * i <= n; i++) {
            int value = i * i; // Current perfect square

            // Update the dp array for all values >= value
            for (int j = value; j <= n; j++) {
                // Either keep previous min or use current square + dp[j - value]
                dp[j] = min(dp[j - value] + 1, dp[j]);
            }
        }

        return dp[n]; // Minimum number of perfect squares summing to n
    }
};
