// Time: O(2^n), there are 2^n substring for dfs.
// Space: O(n), Only one result in step at the same time.
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void helper(string s, vector<string> &step, vector<vector<string>> &ret) {
        // end of the string, insert steps into result
        if (s.size() == 0) {
            ret.push_back(step);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            if (!isPalindrome(sub))
                continue;

            // choose
            step.push_back(sub);
            // explore
            helper(s.substr(i, s.size()-1), step, ret);
            // unchoose
            step.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> step;
        vector<vector<string>> ret;

        if (s.size() == 0)
            return ret;

        helper(s, step, ret);
        return ret;
    }
};
