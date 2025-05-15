// Time Complexity: O(n), where n is the number of words
// Space Complexity: O(n) for the result vector 'ret'

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ret;
        
        // Always include the first word
        ret.push_back(words[0]);
        
        // Add word to result if its group differs from the previous word's group
        for (int i = 1; i < n; i++) {
            if (groups[i] != groups[i-1])
                ret.push_back(words[i]);
        }
        
        return ret;
    }
};

