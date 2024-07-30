// TC:O(n)
// SC:O(n)
class Solution {
public:
    int _rob(vector<int> nums) {
        int n = nums.size();

        if (n > 1)
            nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            nums[i] = max(nums[i-2] + nums[i], nums[i-1]);
        }
        return nums[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1(nums.begin() + 1, nums.end());
        vector<int> v2(nums.begin(), nums.end() - 1);

        if (n == 1)
            return nums[0];

        return max(_rob(v1), _rob(v2));
    }
};
