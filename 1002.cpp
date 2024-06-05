// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> letters(26, INT_MAX);
        vector<string> ret;

        for (int i = 0; i < words.size(); i++) {
            vector<int> tmp(26, 0);
            for (auto c : words[i]) {
                tmp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                letters[i] = min(letters[i], tmp[i]);
            }
        }
        for (int i = 0; i < 26; i++) {
            while (letters[i]--) {
                ret.push_back(string(1, 'a' + i));
            }
        }
        return ret;
    }
};
