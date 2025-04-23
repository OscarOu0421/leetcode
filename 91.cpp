// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(n), for the dp array

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();                // Length of the input string
        vector<int> dp(n, 0);            // dp[i] stores the number of ways to decode s[0..i]

        // Base case: If the first character is '0', no valid decoding
        dp[0] = s[0] == '0' ? 0 : 1;

        // Iterate through the string starting from index 1
        for (int i = 1; i < n; i++) {
            int digit1 = s[i] - '0';            // Current single digit
            int digit2 = stoi(s.substr(i - 1, 2)); // Two-digit number ending at current position

            // If current digit is non-zero, we can decode it as a single letter
            if (digit1 != 0)
                dp[i] += dp[i - 1];

            // If two-digit number is valid (10–26), we can decode it as one letter
            if (digit2 >= 10 && digit2 <= 26)
                dp[i] += i >= 2 ? dp[i - 2] : 1;
        }

        return dp[n - 1];               // Total number of decoding ways
    }
};
