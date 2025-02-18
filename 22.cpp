// TC: O(2^2n)
// SC: O(2^2n * n)
class Solution {
public:
    void helper(int n, int open, int close, string str, vector<string> &ret) {
        if (str.length() == n * 2) {
            ret.push_back(str);
            return;
        }
        if (open < n)
            helper(n, open + 1, close, str + "(", ret);
        if (close < open)
            helper(n, open, close + 1, str + ")", ret);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        helper(n, 0, 0, "", ret);
        return ret;
    }
};
