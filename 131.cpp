// Time Complexity: O(2^n * n), where n is the length of the string.
// - There are up to 2^n possible partitions.
// - Each partition takes up to O(n) time to verify palindromes and copy strings.
// Space Complexity: O(n) for the recursion call stack and path storage.

class Solution {
public:
    // Utility function to check if a string is a palindrome
    bool ispalin(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    // Helper function to generate all palindrome partitions
    void helper(string s, int start, vector<string> path, vector<vector<string>> &ret) {
        string cur = "";

        // Base case: if start reached end of string, store the current path
        if (start == s.size())
            ret.push_back(path);

        // Explore all substrings starting from current index
        for (int i = start; i < s.size(); i++) {
            cur += s[i];                  // Append character to current substring
            if (!ispalin(cur))            // Skip if not palindrome
                continue;

            path.push_back(cur);          // Choose this palindrome
            helper(s, i + 1, path, ret);  // Recurse on remaining substring
            path.pop_back();              // Backtrack
        }
    }

    // Main function to return all palindrome partitions
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        helper(s, 0, {}, ret);            // Start DFS from index 0
        return ret;
    }
};
