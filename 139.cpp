// Time: O(n^3), dp: O(n^2), substr: O(n)
// Space: O(n + m), n is string size, m is dict size
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, false); // dp is 1 indexed
        unordered_set<string> set;
        
        for (auto word : wordDict) {
            set.insert(word);
        }

        // empty string is allowed with any wordDict
        dp[0] = true;

        // From each i, check if you can make word ending with i.
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                string sub = s.substr(j, i-j+1);
                // If we make a word from s[j, i], 
                // then we need to check if s[0, j] is valid.
                if (set.count(sub)) {
                    dp[i+1] = dp[j];

                    // s[j, i] is valid and s[0, j] is valid
                    // then s[0, i] is valid
                    if (dp[i+1])
                        break;
                }
            }
        }
        return dp[n];
    }
};
