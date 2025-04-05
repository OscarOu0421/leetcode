/*
Time Complexity: Exponential in worst case: O(2^n)
- At each character, you can potentially branch into multiple valid words.
- In the worst case (e.g., all 1-letter valid words), you may explore nearly all subsets of positions.

Space Complexity: O(n) recursion depth + output size
- The recursion can go as deep as the length of the string (O(n)).
- Plus the space used by the result vector which depends on the number and length of valid sentences.
*/

class Solution {
public:
    // Helper DFS function to build valid sentences
    void dfs(string s, vector<string> &wordDict, vector<string> &ret, string sentence, int cur) {
        int n = s.size();

        // Base case: if we've reached the end of the string
        if (cur == n) {
            ret.push_back(sentence);  // Add the constructed sentence
            return;
        }

        // Try matching every word in the dictionary
        for (const string& word : wordDict) {
            int len = word.size();

            // Skip if remaining string is too short
            if (cur + len > n)
                continue;

            // If substring matches a word
            if (s.substr(cur, len) == word) {
                string tmp = sentence;
                tmp += (cur == 0 ? word : " " + word);  // Avoid leading space on first word
                dfs(s, wordDict, ret, tmp, cur + len);  // Recurse with new index
            }
        }
    }

    // Main function to return all word break combinations
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        dfs(s, wordDict, ret, "", 0);  // Start DFS from index 0
        return ret;
    }
};
