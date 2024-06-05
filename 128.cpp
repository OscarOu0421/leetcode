// Time: O(n)
// Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int ret = 0;

        for (auto num : nums) {
            set.insert(num);
        }
        for (auto num : nums) {
            // Start with minimum number of the consecutive sequence.
            if (set.count(num - 1) == 0) {
                int tmp = 1;
                while (set.count(++num)) {
                    tmp++;
                }
                ret = max(ret, tmp);
            }
        }
        return ret;
    }
};
