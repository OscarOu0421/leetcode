/*
Time Complexity: O(n * m * l)
- n = length of input string `s`
- m = number of words in `wordDict`
- l = average length of the words (for substring comparison)

Space Complexity: O(n)
- We use a dp array of size n + 1
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);  // dp[i] means s[0..i-1] can be segmented
        dp[0] = true;  // empty string is always breakable

        for (int i = 1; i <= n; i++) {
            for (const string& word : wordDict) {
                int len = word.size();
                if (i >= len && s.substr(i - len, len) == word && dp[i - len]) {
                    dp[i] = true;
                    break;  // already breakable, skip other words
                }
            }
        }
        return dp[n];  // whether the whole string can be segmented
    }
};
