/*
 Time Complexity (TC):
 - O(4^n)
   n = digits.size()
   Each digit can map to at most 4 letters (for '7' and '9').
   In the worst case, we explore all combinations.

 Space Complexity (SC):
 - O(n) recursion depth + O(4^n) for output
   n = digits.size()
   The recursion stack can go up to depth n, and the output vector stores all combinations.
*/

class Solution {
public:
    // DFS helper to build combinations
    void dfs(const string &digits, unordered_map<int, vector<char>> &m, 
             vector<string> &ret, string s) {
        if (digits.empty()) {
            ret.push_back(s);
            return;
        }

        int digit = digits[0] - '0';
        for (char c : m[digit]) {
            // Recurse on remaining digits, append current character
            dfs(digits.substr(1), m, ret, s + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) return ret;  // edge case: empty input

        unordered_map<int, vector<char>> m = {
            {2, {'a','b','c'}}, {3, {'d','e','f'}}, {4, {'g','h','i'}},
            {5, {'j','k','l'}}, {6, {'m','n','o'}}, {7, {'p','q','r','s'}},
            {8, {'t','u','v'}}, {9, {'w','x','y','z'}}
        };

        dfs(digits, m, ret, "");
        return ret;
    }
};

