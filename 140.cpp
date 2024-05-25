// Time: O(2^n), total number of the subset is 2^n
// Space: O(n), the length of the step is equal to the string.
class Solution {
public:
    void insertRet(vector<string> &step, vector<string> &ret) {
        string sentance = "";
        for (auto word : step) {
            sentance += word + " ";
        }
        // Remove the last char.
        sentance.pop_back();
        ret.push_back(sentance);
    }
    void dfs(string s, unordered_set<string> &set, vector<string> &step, vector<string> &ret) {
        // End of the string, construct the sentance into the result.
        if (s.size() == 0) {
            insertRet(step, ret);
            return;
        }
        for (int i = 0; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            // Whether the substring is in the dictionary.
            if (set.count(sub) == 0)
                continue;
            // Choose
            step.push_back(sub);
            // Explore
            dfs(s.substr(i, s.size()), set, step, ret);
            // Unchoose
            step.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        vector<string> step;
        unordered_set<string> set;
        
        // Use set to record the word dictionary
        for (auto word : wordDict) {
            set.insert(word);
        }

        dfs(s, set, step, ret);
        return ret;
    }
};
