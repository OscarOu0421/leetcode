// TC: O(n^3)
// SC: O(1)
class Solution {
public:
    void twosum(vector<int> &nums, int i, int j, int l, int h, long long t, vector<vector<int>> &ret) {

        while (l < h) {
            if (nums[l] + nums[h] == t) {
                ret.push_back({nums[i], nums[j], nums[l], nums[h]});
                int tmpl = l;
                int tmph = h;
                while (l < h && nums[l] == nums[tmpl]) l++;
                while (l < h && nums[h] == nums[tmph]) h--;
            } else if (nums[l] + nums[h] < t)
                l++;
            else
                h--;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                long long t = target - (long long)(nums[i] + nums[j]);
                twosum(nums, i, j, j + 1, n - 1, t, ret);
                while (j+1 < n-2 && nums[j+1] == nums[j]) j++;
            }
            while (i+1 < n-3 && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }
};
