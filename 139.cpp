    /*
     * Time Complexity: O(n^2)
     * - Two loops: i from 1 to n, j from 0 to i
     * - Substring creation is O(n) in worst case, but acceptable in interviews
     *
     * Space Complexity: O(n)
     * - dp array of size n + 1
     * - unordered_set for dictionary
     */

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // Convert wordDict to a hash set for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i] = true if s[0..i-1] can be segmented
        vector<bool> dp(n + 1, false);

        // Base case: empty string
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If prefix is valid and substring exists in dictionary
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // No need to check further
                }
            }
        }

        return dp[n];
    }
};
