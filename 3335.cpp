// Time Complexity: O(t + n), where t is the number of transformations and n is the length of the input string `s`
// Space Complexity: O(t), for the dynamic programming array `dp`

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> dp(t + 26, 0); // dp[i] represents the length of the string produced by a single character after (i - 25) transformations
        int mod = 1e9 + 7;
        int ret = 0;

        // Base case: After 0 transformations, each character is just itself → length = 1
        for (int i = 0; i < 26; i++)
            dp[i] = 1;

	/*
	 * '"a" would be "ab" after 26 transformations.
	 * So dp[26] = dp[0] + dp[1].
	 */
        for (int i = 26; i < t + 26; i++)
            dp[i] = (dp[i - 26] + dp[i - 25]) % mod;

        // Sum the contributions of each character in the original string after t transformations
        for (auto c : s) {
            // Each character 'c' maps to dp[t + (c - 'a')]
            ret = (ret + dp[c - 'a' + t]) % mod;
        }

        return ret;
    }
};
