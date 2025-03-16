// TC: O(n)
// SC: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        unordered_map<char, int> map;

        for (int l = 0, r = 0; r < s.size(); r++) {
            /* add right side of window */
            map[s[r]]++;

            /* delete left side until the windows without dup char */
            while (l <= r && map[s[r]] > 1) {
                map[s[l]]--;
                l++;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
