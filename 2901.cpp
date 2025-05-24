// Time Complexity: O(n^2 * m)
//   - n = number of words
//   - m = length of each word
//   - For each pair of words, `validDistance` is called, which takes O(m)
// Space Complexity: O(n)
//   - For dp, prev, and ret arrays

class Solution {
public:
    // Checks if two words differ by exactly one character
    bool validDistance(string word1, string word2) {
        int diff = 0;

        // Words must be of the same length to compare
        if (word1.size() != word2.size())
            return false;
        
        // Count the number of differing characters
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i])
                diff++;
        }

        // Return true if exactly one character differs
        return diff == 1;
    }

    // Returns the longest subsequence of words such that:
    // - Adjacent words differ by exactly one character
    // - Adjacent words belong to different groups
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int maxLength = 0;
        int maxIndex = -1;
        vector<int> dp(n, 1);     // dp[i] = length of longest valid subsequence ending at i
        vector<int> prev(n, -1);  // prev[i] = previous index in the optimal path
        vector<string> ret;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                // Check if words differ by one char and belong to different groups
                if (groups[j] != groups[i] && validDistance(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            // Update the longest subsequence info
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct the longest valid subsequence using prev[]
        while (maxIndex >= 0) {
            ret.push_back(words[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        reverse(ret.begin(), ret.end()); // Reverse to get correct order
        return ret;
    }
};

