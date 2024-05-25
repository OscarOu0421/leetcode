/* Solution1: DFS + Backtracking */
// Time: O(2^n), 2^n subsets
// Space: O(n), for map
class Solution {
public:
    bool isBeautiful(int num, int k, unordered_map<int, int> &freq) {
        return freq[num - k] == 0 && freq[num + k] == 0;
    }
    void dfs(vector<int> &nums, int i, int k, int &ret, unordered_map<int, int> &freq) {
        if (i == nums.size()) {
            ret++;
            return;
        }
        
        // not take nums[i]
        dfs(nums, i+1, k, ret, freq);

        // take nums[i]
        if (isBeautiful(nums[i], k, freq)) {
            // choose
            freq[nums[i]]++;
            // explore
            dfs(nums, i+1, k, ret, freq);
            // unchoose
            freq[nums[i]]--;
        }
        return;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ret = 0;
        unordered_map<int, int> freq;

        if (nums.size() == 0)
            return ret;
        
        dfs(nums, 0, k, ret, freq);

        // result should not includ empty set,
        // delete one for empty set.
        return ret-1;
    }
};
